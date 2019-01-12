/**
  ******************************************************************************
  * @file    dmacfg.h
  * @author  ZHD Application Team
  * @version V1.1.2
  * @date    17-Mar-2015
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_DMA_CFG_H
#define __BSP_DMA_CFG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
void DMAStreamxConfig(DMA_Stream_TypeDef *DMA_Streamx,uint32_t DMA_Channelx,uint32_t PeripheralBaseAddr,\
						uint32_t MemoryBaseAddr,uint32_t DMAChannel_Dir, uint32_t DMAChannel_Mode,uint16_t BufferSize);
void DMAStreamxNVICConfig(DMA_Stream_TypeDef *DMA_Streamx,uint32_t DMA_IT,uint8_t NVIC_IRQChannel,
													uint8_t NVIC_IRQChannelPreemptionPriority,uint8_t NVIC_IRQChannelSubPriority);
	 
	 
	 
#endif
