#ifndef _BSP_USART_CFG_H
#define	_BSP_USART_CFG_H

#include "main.h"
#include <stdio.h>
#include <stdbool.h>




void USART1_Config(void);
//void USARTx_Printf(USART_TypeDef* USARTx, char *Data,...);

int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif /* _BSP_USART_CFG_H */
