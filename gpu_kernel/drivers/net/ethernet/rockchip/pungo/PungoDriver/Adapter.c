#include <linux/kernel.h>	/* printk() false*/
#include <linux/string.h>	/* memset*/

#include "Shared.h"
#include "Adapter.h"
#include "gmac.h"

#if 0
#define US	1000
#define DELAYTIME 200*US
static unsigned long  LastTime = 0;
static unsigned int i = 0;
static long int MaxTimeOut = 1000000;
static long int MinTimeOut = 1000000;
static long int MaxDelt = 0;
static long int MinDelt = 0;
#endif

unsigned short Adapter_Send(const void *pbData, unsigned short dwLength)
{
	unsigned char *SKB_Packet = NULL;
	unsigned int SKB_Length;
	
	SKB_Packet = (unsigned char *)(pbData);
	ASSERT( SKB_Packet != NULL )
	
	SKB_Length =  (unsigned int )(dwLength);
	ASSERT( SKB_Length > 0 )
	
	return rtl8211_xmit(SKB_Packet, SKB_Length);
}

void Adapter_Get(Adapter_t *_This, const unsigned char *pbData, int dwLength)
{
#if 0
	unsigned long  CurrentTime = 0;
	long int _TmpMsec;
	
	//memcpy(&CurrentTime, &skb->data[12] , sizeof(CurrentTime));
	CurrentTime = *(unsigned long *)&pbData[12];
	//printk(KERN_EMERG "CurrentTime = 0x%lx LastTime =0x%lx\n",CurrentTime,LastTime);

	if (i == 0)
	{
		LastTime = CurrentTime; 
	}else{
		_TmpMsec = abs(CurrentTime - LastTime);
		
		MaxTimeOut = _TmpMsec > MaxTimeOut ? _TmpMsec : MaxTimeOut;//最大
		MinTimeOut = _TmpMsec < MinTimeOut ? _TmpMsec : MinTimeOut;//最小

		LastTime = CurrentTime;

		MaxDelt = MaxTimeOut - 1000000; 
		MinDelt = MinTimeOut - 1000000;

		if (abs(MaxDelt) > (50 * 1000) && abs(MaxDelt) < (100 * 1000))
		{
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_50or100_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		} 
		else if (abs(MaxDelt) > (100 * 1000) && abs(MaxDelt) < (200 * 1000)) 
		{	//误差大于100us 小于 200us
			//printk(KERN_EMERG "%d MaxTimeOut = %ld MinTimeOut = %ld MaxDelt = %ld MinDelt = %ld\n", ei, MaxTimeOut, MinTimeOut, MaxDelt, MinDelt);
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_100or200_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		}	
		else if  (abs(MaxDelt) > (200 * 1000) && abs(MaxDelt) < (400 * 1000)) 
		{	//误差大于200us 小于 400us
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_200or400_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		}
		else if  (abs(MaxDelt) > (400 * 1000) && abs(MaxDelt) < (600 * 1000)) 
		{	//误差大于400us 小于 600us
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_400or600_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		}
		else if  (abs(MaxDelt) > (600 * 1000) && abs(MaxDelt) < (800 * 1000)) 
		{	//误差大于600us 小于 800us
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_600or800_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		}
		else if  (abs(MaxDelt) > (800 * 1000) && abs(MaxDelt) < (1000 * 1000)) 
		{	//误差大于800us 小于 1000us
			g_Device->m_Adapter.m_Kernel->m_SharedMemory->m_800or1000_count++;
			MaxTimeOut = MinTimeOut = 1000000;
		}
	
	}

	i++;
#else
	_This->m_Kernel->m_SharedMemory->m_recvecat_count++;
#endif
	return;
}

int RegisterProtocol(void)
{
	int ret;
	printk("%s()\n",__FUNCTION__);

	ret = stmmac_init();
	if (ret )
	{
		printk("RegisterProtocol error\n");
		error = -ret;
		return -ret;
	}

	return true;
}


void DeregisterProtocol(void)//取消已注册协议
{
	printk("%s()\n",__FUNCTION__);

	stmmac_exit();
}
