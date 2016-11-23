//
//

#ifndef _DEVICEENTRY_H_
#define _DEVICEENTRY_H_

#include "MemoryMap.h"
#include "Adapter.h"
#include "Timer.h"
#include "Kernel.h"

typedef struct Device
{
//public:
	MemoryMap_t     m_MemoryMap;
	Adapter_t       m_Adapter;
	Timer_t         m_Timer;
	Kernel_t        m_Kernel;
}Device_t;

typedef struct InLicense
{
//public:
	char PassCode[64];
	char RequestCode[64];
}Input_License_Info;

typedef struct OutLicense
{
//public:
	bool Result;
	unsigned int GenerateTime;
	char RequestParas[32];
}Output_License_Info;

void Device_InitDevice(Device_t *_This);
void Device_UnDevice(Device_t *_This);
int Device_Add(void);

#endif

