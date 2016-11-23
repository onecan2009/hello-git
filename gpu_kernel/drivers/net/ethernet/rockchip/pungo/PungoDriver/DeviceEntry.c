#include <linux/kernel.h>	/* printk() false*/
#include <linux/string.h>	/* memset*/
//#include <linux/freezer.h>	/* kmalloc*/
#include <linux/slab.h>	/* kmalloc*/

#include "Shared.h"
#include "DeviceEntry.h"

Device_t *g_Device = NULL;

void Device_InitDevice(Device_t *_This)
{
	const char Kernel_data[] = "兄弟 不都是朝一个方向 但无论去哪里 心都在一起";
	printk("%s()\n",__FUNCTION__);

	MemoryMap_InitMemoryMap(&_This->m_MemoryMap);
	if (MemoryMap_Map(&_This->m_MemoryMap, sizeof(KernelSharedMemory_t)) < 0)//terry 2015-6-23
	{
		printk("error:call function MemoryMap_Map error\n");
		error = -ENOMEM;//12	/* Out of memory */
		while(1);
	}
	_This->m_Kernel.m_SharedMemory = (KernelSharedMemory_t *)_This->m_MemoryMap.m_kernelModeVirtualAddress;
	memset(_This->m_Kernel.m_SharedMemory, 0, sizeof(KernelSharedMemory_t));
#if 1	//临时测试，完成后删掉
	memcpy (_This->m_Kernel.m_SharedMemory->m_KernerData, Kernel_data, sizeof(Kernel_data));
#endif

	Kernel_InitKernel(&_This->m_Kernel);
	Timer_InitTimer(&_This->m_Timer);
	
	_This->m_Adapter.m_Kernel = &_This->m_Kernel;
	_This->m_Timer.m_Kernel = &_This->m_Kernel;
	//_This->m_Kernel.m_PdoFrame.m_Adapter = &_This->m_Adapter;
}

void Device_UnDevice(Device_t *_This)//运行析构
{
	printk("%s()\n",__FUNCTION__);
#if 0
//临时测试，完成后删掉
	Timer_Cancel(&_This->m_Timer);
	Adapter_Close(&_This->m_Adapter);
	MemoryMap_Unmap(&_This->m_MemoryMap);
#endif
#if 1
	Timer_UnTimer(&_This->m_Timer);
	Kernel_UnKernel(&_This->m_Kernel);
	
	MemoryMap_Unmap(&_This->m_MemoryMap);
	MemoryMap_UnMemoryMap(&_This->m_MemoryMap);
#endif
}

int Device_Add(void)
{
	printk("%s()\n",__FUNCTION__);
	//int t;
	//t = add(1,2);
	//printk("kmalloc Device_t \n");
	TRACE("kmalloc Device_t \n");
	//kmalloc特殊之处在于它分配的内存是物理上连续的 GFP_KERNEL:内核内存的正常分配. 可能睡眠.
	//kmalloc() 分配连续的虚拟地址，用于小内存分配。get_free_page() 分配连续的虚拟地址，用于整页分配
	g_Device = kmalloc(sizeof(*g_Device), GFP_KERNEL);
	if (!g_Device)
	{
		printk("%s()内存申请失败\n",__FUNCTION__);
		error = -ENOMEM;//12	/* Out of memory */
		return -ENOMEM;
	}

	Device_InitDevice(g_Device);//运行构造

	return true;
}


