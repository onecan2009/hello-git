//
//

#ifndef _TIMER_H_
#define _TIMER_H_
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include "Kernel.h"

typedef struct Timer
{
//public:
	//void (*SetFunction)();
	//void (*CancelFunction)();
	Kernel_t          *m_Kernel;
	//KTIMER            m_Timer;
	//KDPC              m_Dpc;
#ifdef TASKLET_ENABLE
	struct tasklet_struct irq_tasklet;
#endif
	atomic_t m_Tx_Lock;
	spinlock_t	m_Lock;
//private:
	void __iomem		*regs_timer0;
}Timer_t;

void GetTimer0Value(unsigned long *Value);

void Timer_InitTimer(Timer_t *_This);
void Timer_UnTimer(Timer_t *_This);
int Timer_Set(Timer_t *_This);
void Timer_Cancel(Timer_t *_This);

#endif
