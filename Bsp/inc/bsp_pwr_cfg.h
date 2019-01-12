#ifndef BSP_PWR_CFG_H
#define BSP_PWR_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f2xx.h"
	 


#define PWRPORT                 GPIOA 
#define PWRPIN	                GPIO_Pin_7 
#define PWR_RCC_PERIPHPORT      RCC_AHB1Periph_GPIOA
     
#define PWR_ON()	             GPIO_SetBits(PWRPORT,PWRPIN)
#define PWR_OFF()	             GPIO_ResetBits(PWRPORT,PWRPIN)

void PWRGPIOConfig(void);
#endif
