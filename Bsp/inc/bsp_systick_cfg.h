#ifndef __BSP_SYSTICK_CFG_H
#define __BSP_SYSTICK_CFG_H

#include "stm32f10x.h"
#include <stdbool.h>


void BSP_SysTickInit(void);
void BSP_Delay_ms(u32 nTime);


#endif /* __BSP_SYSTICK_CFG_H */
