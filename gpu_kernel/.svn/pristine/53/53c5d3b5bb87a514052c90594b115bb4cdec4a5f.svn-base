//
//

#ifndef _ADAPTER_H_
#define _ADAPTER_H_

//#include <linux/spinlock.h>
#include "Kernel.h"

typedef struct Adapter
{
//public:
	Kernel_t        *m_Kernel;
	unsigned long    m_PacketFilter;
	//spinlock_t 		my_spinlock;

}Adapter_t;

int RegisterProtocol(void);

void DeregisterProtocol(void);

unsigned short Adapter_Send(const void *pbData, unsigned short dwLength);

//int Adapter_Open(Adapter_t *_This);

//void Adapter_Close(Adapter_t *_This);

#endif
