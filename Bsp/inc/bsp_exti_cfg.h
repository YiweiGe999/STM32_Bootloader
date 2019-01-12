#ifndef _BSP_EXTI_CFG_H
#define	_BSP_EXTI_CFG_H

#include "stm32f10x.h"

void BSP_ExtiPortInit(void);

#define  CTR_SWITCH(CtrPort,CtrPin,a)	if (a)	\
                                GPIO_SetBits(CtrPort,CtrPin);\
                                else		\
                                GPIO_ResetBits(CtrPort,CtrPin)


#endif /* _BSP_EXTI_CFG_H */
