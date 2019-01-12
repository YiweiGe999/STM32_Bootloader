	/******************** (C) COPYRIGHT Hi-Target  ********************
 * 文件名  ：bsp_dma_cfg.c
 * 描述    ：DMA配置库     
 * 实验平台：V6 RTK
 * 库版本  ：V1.0.0
 * 作者    ：
 * 博客    ：
 * 修改时间: 2015-3-6
**********************************************************************************/	
/**
  ******************************************************************************
  * @file    bsp_dma_cfg.c 
  * @author  ZHD  Technology Team
  * @version V1.0.0
  * @date    6-March-2015
  * @brief   bsp_dma_cfg
  ******************************************************************************
  * @attention
  * 
  * 
  ******************************************************************************
  */
#include "bsp_dma_cfg.h"

void DMAStreamxConfig(DMA_Stream_TypeDef *DMA_Streamx,uint32_t DMA_Channelx,uint32_t PeripheralBaseAddr,\
						uint32_t MemoryBaseAddr,uint32_t DMAChannel_Dir, uint32_t DMAChannel_Mode,uint16_t BufferSize)
{
    DMA_InitTypeDef  DMA_InitStructure;
      /* Determine the DMA to which belongs the stream */
    if (DMA_Streamx < DMA2_Stream0)
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1,ENABLE);
    } 
    else 
    {
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);
    }
    DMA_DeInit(DMA_Streamx);

    while (DMA_GetCmdStatus(DMA_Streamx) != DISABLE){}//等待DMA可配置 
	
    /* 配置 DMA Stream */
    DMA_InitStructure.DMA_Channel = DMA_Channelx;  
    DMA_InitStructure.DMA_PeripheralBaseAddr = PeripheralBaseAddr;
    DMA_InitStructure.DMA_Memory0BaseAddr = MemoryBaseAddr;
    DMA_InitStructure.DMA_DIR = DMAChannel_Dir;
    DMA_InitStructure.DMA_BufferSize = BufferSize;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMAChannel_Mode;
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA_Streamx, &DMA_InitStructure);
    DMA_Cmd(DMA_Streamx, DISABLE);	
}

void DMAStreamxNVICConfig(DMA_Stream_TypeDef *DMA_Streamx,uint32_t DMA_IT,uint8_t NVIC_IRQChannel,
													uint8_t NVIC_IRQChannelPreemptionPriority,uint8_t NVIC_IRQChannelSubPriority)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    DMA_ITConfig(DMA_Streamx, DMA_IT, ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQChannel;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=NVIC_IRQChannelPreemptionPriority;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =NVIC_IRQChannelSubPriority;		
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			
    NVIC_Init(&NVIC_InitStructure);	
}

/*********************************************END OF FILE**********************/

