#ifndef __HFIC_H
#define __HFIC_H

#include "bsp_led_cfg.h"
#include "bsp_systick_cfg.h"
#include "bsp_key_cfg.h"


#define HFIC_LedInit()		BSP_LedInit()
#define HFIC_LedSwitch(u16LedIdCpy,u8LedStatus)	BSP_LedSwitch(u16LedIdCpy,u8LedStatus)


#define HFIC_KeyInit()		BSP_KeyInit()
#define HFIC_enuKeyPress()	    BSP_CheckKeyState()

#define Delay_ms(u32Msec)  BSP_Delay_ms(u32Msec)
#define SysTick_Init()		 BSP_SysTickInit()
#endif 
