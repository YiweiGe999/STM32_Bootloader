#ifndef _BSP_USART_CFG_H
#define	_BSP_USART_CFG_H

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include <stdio.h>    
//#include <stdbool.h>



#define BSP_USART_BUADRATE    115200
#define BSP_USART_RX_PIN 	    GPIO_Pin_10
#define BSP_USART_TX_PIN      GPIO_Pin_9

#define BSP_USART 						USART1
#define BSP_USART_PORT     		GPIOA
#define BSP_USART_IRQn        USART1_IRQn
#define BSP_RCC_USART_PORT  	RCC_APB2Periph_GPIOA
#define BSP_RCC_USART			  	RCC_APB2Periph_USART1

void BSP_UsartInit(void);
//void USARTx_Printf(USART_TypeDef* USARTx, char *Data,...);
void BSP_UsartSendBlock(u8 *u8BlockData);


#define USE_MICRO_LIB

#if (defined(USE_MICRO_LIB))
	int fputc(int ch, FILE *f);
	int fgetc(FILE *f);
	//void BSP_UsartSendStr(u8 *str);
#endif

#endif /* _BSP_USART_CFG_H */
