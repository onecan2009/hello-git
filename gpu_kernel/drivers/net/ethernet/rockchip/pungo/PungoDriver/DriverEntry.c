#include <linux/module.h>   /*module_init()*/
#include <linux/kernel.h>	/* printk() */
#include <linux/init.h>		/* __init __exit */
#include <linux/fs.h>		/* file_operation */
#include <asm/uaccess.h>	/* copy_to_user, copy_from_user */
//#include <linux/device.h>   /* class ,class_create ,device_create 等*/
#include <linux/errno.h>	/* Error number */
//#include <linux/delay.h>	/* udelay */
//#include <asm/delay.h>
//#include <linux/clk.h>		//clk_get() , clk_enable()
#include <linux/string.h>   //memcpy
#include <linux/miscdevice.h> //miscdevice
#include <linux/slab.h>	/* kfree*/
#include <linux/mm.h>		/* vm_area_struct remap_pfn_range*/

#include <Pungo/Kernel/IoControlCode.h>
#include "DeviceEntry.h"

#define DRIVER_NAME	"LPungo1.3"

extern Device_t *g_Device;
int error;//全局错误号
/*
	KERN_EMERG		用于紧急事件,一般是系统崩溃前的提示信息
	KERN_ALERT		用于需要立即采取动作的场合
	KERN_CRIT		临界状态,通常设计验证的硬件或软件操作失败
	KERN_ERR		用于报告错误状态.设备驱动程序通常会用它报告来自硬件的问题
	KERN_WARNING	就可能出现的问题提出警告.这些问题通常不会对系统造成严重破坏
	KERN_NOTICE		有必要提示的正常情况.许多安全相关的情况用这个级别汇报
	KERN_INFO		提示性信息.有很多驱动程序在启动时用这个级别打印相关信息
	KERN_DEBUG		用于调试的信息
*/
static int Device_t_open(struct inode *inode, struct file *filp)
{
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
#if 1
	if (Timer_Set(&g_Device->m_Timer) < 0)
	{
		printk(KERN_CRIT "call function Timer_Set error = %d\n",error);
		return error;
	}
#endif

	return 0;
}

static int Device_t_release(struct inode *inode, struct file *filp)
{
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
#if 1
	Timer_Cancel(&g_Device->m_Timer);
#endif
	return 0;
}

static int Device_t_mmap(struct file *file, struct vm_area_struct *vma)
{
	return 0;
}

static long Device_t_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	void __user *argp = (void __user *)arg;//指向用户地址空间

	printk(KERN_CRIT "%s()\n",__FUNCTION__);

	switch (cmd)
	{
	case KERNEL_IOCTL_GET_SHARED_MEMORY_ADDR:
		return copy_to_user(argp, &g_Device->m_MemoryMap.m_UserModePhysicalAddress,
				sizeof(g_Device->m_MemoryMap.m_UserModePhysicalAddress)) ? -EFAULT : 0;//EFAULT:14	/* Bad address */

	case KERNEL_IOCTL_GET_SHARED_MEMORY_SIZE:
		return copy_to_user(argp, &g_Device->m_MemoryMap.m_phymemSize,
				sizeof(g_Device->m_MemoryMap.m_phymemSize)) ? -EFAULT : 0;//EFAULT:14	/* Bad address */

	default:
		return -ENOIOCTLCMD;//	515	/* No ioctl command */
	}

	return 0;
}

static ssize_t Device_t_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
	return 0;
}

static ssize_t Device_t_read(struct file *filp, char *pBuffer, size_t count, loff_t *f_pos)
{
	printk(KERN_CRIT "%s()\n",__FUNCTION__);
	return count;
}

static const struct file_operations Device_t_fops = {
	.owner					= THIS_MODULE,
	.open 						= Device_t_open,
	.mmap					= Device_t_mmap,			//用来请求将设备内存映射到进程的地址空间. 如果这个方法是 NULL, mmap 系统调用返回 -ENODEV.
	.unlocked_ioctl		= Device_t_ioctl,				//在多核情况下，必须在unlocked_ioctl方法中自行实现锁机制，
	.write						= Device_t_write,
	.read						= Device_t_read,
	.release					= Device_t_release,
};

static struct miscdevice misc = {
	.minor	 = MISC_DYNAMIC_MINOR,
	.name	= DRIVER_NAME,
	.fops	= &Device_t_fops,
};

static int __init Driver_init(void)
{
	int ret;
	printk("%s()\n",__FUNCTION__);
	
	if (RegisterProtocol() < 0)
	{
		printk("RegisterProtocol error\n");
		return error;
	}
	
	if (Device_Add() < 0)
	{	
		printk("Device_Add load error\n");

		if (g_Device != NULL)
		{
			printk("kfree:Device_t\n");

			kfree(g_Device);//将申请的结构体注销
		}
		DeregisterProtocol();//取消已注册协议

		return error;
	}
	/* Driver register */
		//该函数是用来注册一个杂项设备的。返回值为一个整数，如果注册成功返回0，注册失败则返回失败的错误代码
	ret = misc_register(&misc);
	if (ret != 0)
	{
		printk("cannot register miscdev on minor=%d (%d)\n",MISC_DYNAMIC_MINOR, ret);
		DeregisterProtocol();//取消已注册协议
		Device_UnDevice(g_Device);		
		kfree(g_Device);//将申请的结构体注销
		return ret;
	}
	return 0;
}

static void __exit Driver_exit(void)
{
	/* Module exit code */
	printk("%s()\n",__FUNCTION__);

	DeregisterProtocol();//取消已注册协议
	
	Device_UnDevice(g_Device);//运行析构

	//printk("TimeoutCount = %ld\n",g_Device->m_Kernel.m_TimeoutCount);

	printk("kfree:Device_t\n");
	kfree(g_Device);//将申请的结构体注销
	
	misc_deregister(&misc);
	return;
}

module_init(Driver_init);
module_exit(Driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("terry");
