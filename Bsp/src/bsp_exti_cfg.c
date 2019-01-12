	/******************** (C) COPYRIGHT Hi-Target  ********************
 * 文件名  ：bsp_exti_cfg.c
 * 描述    ：外部中断      
 * 实验平台：SLC
 * 库版本  ：V1.0.0
 * 作者    ：
 * 博客    ：
 * 修改时间: 2015-10-29
**********************************************************************************/	
/**
  ******************************************************************************
  * @file    bsp_exti_cfg.c 
  * @author  ZHD  Technology Team
  * @version V1.0.0
  * @date    29-Oct-2015
  * @brief   exti
  ******************************************************************************
  * @attention
  * EXTI<----->PE15 
  ******************************************************************************
  */
  
#include "bsp_exti_cfg.h"



/*******************************************************************************
 * 名称: EXTI15_Config
 * 功能: PE15外部中断
 * 形参: 无
 * 返回: 无
 * 说明: 
 ******************************************************************************/
void EXTI15_Config(void)
{

	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	/* Configure PE15 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* Connect EXTI Line15 to PE15 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource15);

	/* Configure EXTI Line15 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set EXTI15_10 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}
 
 

/*********************************************END OF FILE**********************/
