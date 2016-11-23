//
//

#ifndef _MEMORYMAP_H_
#define _MEMORYMAP_H_

#include "Shared.h"

typedef struct MemoryMap
{
	//MDL *m_Mdl;
	unsigned long m_UserModePhysicalAddress;
	unsigned long m_kernelModeVirtualAddress;//terry
	unsigned long m_phymemSize;//terry
	unsigned long m_PageCnt;//terry
	unsigned short m_PageOrder;//terry

}MemoryMap_t;

void MemoryMap_InitMemoryMap(MemoryMap_t *_This);
void MemoryMap_UnMemoryMap(MemoryMap_t *_This);
int MemoryMap_Map(MemoryMap_t *_This, unsigned long Length);
void MemoryMap_Unmap(MemoryMap_t *_This);

#endif
