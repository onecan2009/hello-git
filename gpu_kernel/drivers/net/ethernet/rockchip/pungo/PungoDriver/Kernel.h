//
//

#ifndef _KERNEL_H_
#define _KERNEL_H_

//#include <Pungo/Kernel/SharedMemory.h>
#include "../SDK/Include/Pungo/Kernel/SharedMemory.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Kernel
{
//public:
#ifdef __LINUX_PUNGGOL_CROSS__
	KernelSharedMemory_t  *m_SharedMemory;
#else
	KernelSharedMemory_t  m_SharedMemory;
#endif
	//PdoFrame_t            m_PdoFrame;
	//PdoVm_t               m_PdoVm;
	//PdoPosition_t         m_PdoPosition;
	//PdoPulse_t            m_PdoPulse;
	//CPlcImplement         m_PlcImplement;
	//CDeviceState          m_DeviceState;

//private:
	bool                  m_Start;
	INT64                 m_Pf;
	INT64                 m_Pc;

}Kernel_t;

void Kernel_InitKernel(Kernel_t *_This);
void Kernel_UnKernel(Kernel_t *_This);
void Kernel_OnTimer(Kernel_t *_This);

#ifdef __cplusplus
}
#endif

#endif

