/************************(C) COPYRIGHT YiweiGe******************************

LED config



**********************************************************************************/
#ifndef BSP_LED_CFG_H
#define BSP_LED_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "type_name.h" 

#define	LED0		GPIO_Pin_0
#define	LED1		GPIO_Pin_1
#define	LED2		GPIO_Pin_2
#define	LED3		GPIO_Pin_3
#define	LED4		GPIO_Pin_4
#define	LED5		GPIO_Pin_5
#define	LED6		GPIO_Pin_6
#define	LED7		GPIO_Pin_7	 

#define LED_PORT		GPIOA

#define LED_RCC_PERIPHPORT  RCC_APB2Periph_GPIOA


#define LED_ON  0
#define LED_OFF 1






extern void BSP_LedInit(void);
extern void BSP_LedSwitch(u16 u16LedIdex,u8 u8Status);


#endif









