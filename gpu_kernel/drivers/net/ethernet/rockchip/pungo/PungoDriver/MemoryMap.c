#include <linux/kernel.h>	/* printk() false*/
#include <net/sock.h>		/* SetPageReserved*/
#include <linux/module.h>	/* get_order*/
#include <linux/string.h>	/* memset*/

#include "MemoryMap.h"


void MemoryMap_InitMemoryMap(MemoryMap_t *_This)
{
	printk("%s()\n",__FUNCTION__);

	_This->m_UserModePhysicalAddress = 0;
	_This->m_kernelModeVirtualAddress = 0;
	_This->m_phymemSize = 0;
	_This->m_PageCnt = 0;
	_This->m_PageOrder = 0;

	return;
}

void MemoryMap_UnMemoryMap(MemoryMap_t *_This)
{
	printk("%s()\n",__FUNCTION__);
	
	ASSERT(_This->m_UserModePhysicalAddress == 0);
	ASSERT(_This->m_kernelModeVirtualAddress == 0);
	ASSERT(_This->m_phymemSize == 0);
	ASSERT(_This->m_PageCnt == 0);
	ASSERT(_This->m_PageOrder == 0);

	return;
}

int MemoryMap_Map(MemoryMap_t *_This, unsigned long Length)
{
	unsigned long page_addr;
	int i;

	printk("%s()\n",__FUNCTION__);

	ASSERT(_This->m_UserModePhysicalAddress == 0);
	ASSERT(_This->m_kernelModeVirtualAddress == 0);
	ASSERT(_This->m_phymemSize == 0);
	ASSERT(_This->m_PageCnt == 0);
	ASSERT(_This->m_PageOrder == 0);

	//printk("%s() get_order = %d\n",__FUNCTION__,get_order(32 * 4096 + 1));
	_This->m_PageOrder = get_order(Length);//得到内存页大小的 2的n次幂
	_This->m_kernelModeVirtualAddress = __get_free_pages(GFP_KERNEL, _This->m_PageOrder);/* allocate 8kB */

	if(!_This->m_kernelModeVirtualAddress)
	{
		printk("init_mem_pool::__get_free_pages error.\n");
		error = -ENOMEM;//12	/* Out of memory */
		return -ENOMEM;
	}
	else
	{
		_This->m_PageCnt = (1 << _This->m_PageOrder);//得到总页数
		_This->m_phymemSize = _This->m_PageCnt * PAGE_SIZE;//PAGE_SIZE = 4096字节 一页大小
		page_addr = _This->m_kernelModeVirtualAddress;
		//printk("size=%08x, page_cnt=%d\n", glb_para.shm_para.mem_size, glb_para.shm_para.page_cnt);
		//内核中申请到页面之后，要调用一下SetPageReserved，相当于告诉系统，这个页面我已经占了。对于每一个申请到的页面，应该都要这样做
		for(i = 0; i <  _This->m_PageCnt; i++)
		{
			SetPageReserved(virt_to_page(page_addr)); /* reserved for used */ //锁住物理页面,可以使页面不被交换
			page_addr += PAGE_SIZE;
		}

		_This->m_UserModePhysicalAddress = __pa(_This->m_kernelModeVirtualAddress); /*__pa:convert virtual address to physical address, which needed by/dev/mem */

		printk("UserModePhysicalAddress = 0x%lx, kernelModeVirtualAddress=0x%lx phymemSize = %ld\n",_This->m_UserModePhysicalAddress, _This->m_kernelModeVirtualAddress, _This->m_phymemSize);
	}

	return true;
}

void MemoryMap_Unmap(MemoryMap_t *_This)
{
	unsigned long page_addr;
	int i;

	printk("%s()\n",__FUNCTION__);

	ASSERT(_This->m_UserModePhysicalAddress != 0);
	ASSERT(_This->m_kernelModeVirtualAddress != 0);
	ASSERT(_This->m_phymemSize != 0);
	ASSERT(_This->m_PageCnt != 0);
	ASSERT(_This->m_PageOrder != 0);

	printk("free_pages:kernelModeVirtualAddress\n");
	page_addr = _This->m_kernelModeVirtualAddress;
	for(i = 0; i < _This->m_PageCnt; i++)
	{
		ClearPageReserved(virt_to_page(page_addr));
		page_addr += PAGE_SIZE;
	}
	free_pages(_This->m_kernelModeVirtualAddress, _This->m_PageOrder);

	_This->m_UserModePhysicalAddress = 0;
	_This->m_kernelModeVirtualAddress = 0;
	_This->m_phymemSize = 0;
	_This->m_PageCnt = 0;
	_This->m_PageOrder = 0;

	return;
}
