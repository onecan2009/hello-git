#include <linux/kernel.h>	/* printk() false*/
#include <linux/string.h>	/* memset*/
#include <linux/rockchip/iomap.h>
#include <linux/time.h>
#include <linux/irq.h>			//set_irq_type ,IRQ_TYPE_EDGE_FALLING
#include <linux/interrupt.h>	//request_irq , free_irq
//#include <linux/err.h>		//IS_ERR

#include "Shared.h"
#include "Timer.h"

#define IRQ_TIMER0	98
#define TIMER_CYCLE	24000 * 2
void __iomem		*Timer0_Value_Register;

void GetTimer0Value(unsigned long *Value)
{
	if (likely(Timer0_Value_Register != NULL))
	{
		*Value =  (TIMER_CYCLE - readl_relaxed(Timer0_Value_Register) ) / 24;
	}
	
	return;
}

void Timer_InitTimer(Timer_t *_This)
{
	printk("%s()\n",__FUNCTION__);
	
	spin_lock_init(&_This->m_Lock);
	
	Timer0_Value_Register = NULL;
	_This->regs_timer0 =  NULL;
	atomic_set(&_This->m_Tx_Lock, 0);
	
}

void Timer_UnTimer(Timer_t *_This)
{
	printk("%s()\n",__FUNCTION__);
	
	ASSERT(Timer0_Value_Register ==  NULL);
	ASSERT(_This->regs_timer0 ==  NULL);
	ASSERT(atomic_read( &_This->m_Tx_Lock) == 0);
}

#ifdef TASKLET_ENABLE
static void OnTimer_tasklet(unsigned long data)
{
	Timer_t *Timer = (Timer_t *)data;
	
	spin_lock(&Timer->m_Lock);
	Kernel_OnTimer(Timer->m_Kernel);//定时扫描MC
	spin_unlock(&Timer->m_Lock);
}
#endif

static irqreturn_t timer0_interrupt (int irq, void *dev_id)
{
	//printk("%s()\n",__FUNCTION__);
	Timer_t *Timer = (Timer_t *)dev_id;
	unsigned long flags;
	
	//atomic_set(&Timer->m_Tx_Lock, 1);
	spin_lock_irqsave(&Timer->m_Lock, flags);
	//PWM_CSTAT = (1<<6)|(PWM_CSTAT & 0x1f);//清除定时器0中断标志
	writel_relaxed(1, Timer->regs_timer0 + 0x18);//Timer n Interrupt Status Register 
	dsb();
	
#ifdef TASKLET_ENABLE
	tasklet_schedule(&Timer->irq_tasklet);//正常优先级和激发软件中断，并立即返回
	//tasklet_hi_schedule(&Timer->irq_tasklet);//高优先级的调度函数
#else
	Kernel_OnTimer(Timer->m_Kernel);//定时扫描MC
#endif	
	
	spin_unlock_irqrestore(&Timer->m_Lock, flags);
	//atomic_set(&Timer->m_Tx_Lock, 0);
	
	return IRQ_HANDLED;
}

static void StartTimer0(void __iomem *regs_timer0)
{
	/* enable timer0 for core */
	writel_relaxed((0 << 0) | (0 << 1) | (1 << 2), regs_timer0  + 0x10);//RK_TIMER_VIRT
	dsb();

	//writel_relaxed(24000*2, regs_timer0  + 0x00);//0x16e3600 = 24000000 0x5dc0 = 24000
	writel_relaxed(TIMER_CYCLE, regs_timer0  + 0x00);//0x16e3600 = 24000000 0x5dc0 = 24000
	writel_relaxed(0x0, regs_timer0  + 0x04);
	dsb();

	writel_relaxed((1 << 0) | (0 << 1) | (1 << 2), regs_timer0 + 0x10);//starat timer0
	dsb();
}

int Timer_Set(Timer_t *_This)
{
	int ret;
	int cpu = 2;//在CPU3
	struct cpumask cpumask;
	
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
	//printk("HZ = %d\n",HZ);//HZ = 256 3.90625ms rk3288=100 10ms
	//printk("S3C_VA_TIMER = %0x\n",(unsigned long)S3C_VA_TIMER);//S3C_VA_TIMER = 0xf4300000
	//IRQF_DISABLED:一旦进入中断不会再响应其他中断
	//IRQF_TIMER：专用于定时中断；
	printk(KERN_CRIT "request_irq:IRQ_TIMER1\n");
	ret = request_irq(IRQ_TIMER0, &timer0_interrupt,  IRQF_DISABLED | IRQF_TIMER, "Timer0", (void *)_This);
	if (ret != 0)
	{
		printk(KERN_CRIT "Register IRQ_TIMER0 failed! ret = %d\n",ret);//
		error = ret;
		return ret;
	}
		
	_This->regs_timer0 = ioremap(RK3288_TIMER0_PHYS, SZ_4K);//将网卡物理地址映射到内核虚礼地址
	if (!_This->regs_timer0)
	{
		printk(KERN_EMERG "failed to ioremap address reg\n");
		
		free_irq(IRQ_TIMER0, (void *)_This);
		return -EINVAL;//22	/* Invalid argument */
	}
	Timer0_Value_Register = _This->regs_timer0 + 0x08;
	
	//微线程初始化函数
	//参数1：用户已定义tasklet_struct变量的地址
	//参数2：tasklet的任务处理函数
	//参数3：func函数的参数
	#ifdef TASKLET_ENABLE
	tasklet_init(&_This->irq_tasklet, OnTimer_tasklet,(unsigned long)_This);
	#endif

	//中断IRQ_TIMER0绑定CPU3
	cpumask_clear(&cpumask);
	cpumask_set_cpu(cpu, &cpumask); 
	irq_set_affinity(IRQ_TIMER0, &cpumask); 
	
	StartTimer0(_This->regs_timer0);//启动定时器0

	return true;
}

void Timer_Cancel(Timer_t *_This)
{
	
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
	
	printk(KERN_CRIT "iounmap:_This->regs_timer0\n");
	
	ASSERT(Timer0_Value_Register !=  NULL);
	ASSERT(_This->regs_timer0 != NULL);
	writel_relaxed((0 << 0) | (0 << 1) | (0 << 2), _This->regs_timer0  + 0x10);// Disabled time1 interupt
	dsb();
	
	atomic_set(&_This->m_Tx_Lock, 0);
	
#ifdef TASKLET_ENABLE	
	tasklet_kill(&_This->irq_tasklet);//使用完毕后，调用以下函数销毁已初始化的微线程
#endif

	iounmap(_This->regs_timer0);
	_This->regs_timer0 = NULL;
	
	Timer0_Value_Register = NULL;
	
	printk(KERN_CRIT "free_irq:IRQ_TIMER0\n");
	free_irq(IRQ_TIMER0, (void *)_This);

}
