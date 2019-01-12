	/******************** (C) COPYRIGHT Hi-Target  ********************
 * 文件名  ：bsp_pwr_cfg.c
 * 描述    ：电源芯片管理    
 * 实验平台：V100 RTK
 * 库版本  ：V1.0.0
 * 作者    ：
 * 博客    ：
 * 修改时间: 2015-3-6
**********************************************************************************/	
/**
  ******************************************************************************
  * @file    bsp_pwr_cfg.c 
  * @author  ZHD  Technology Team
  * @version V1.0.0
  * @date    6-March-2015
  * @brief   bsp_pwr_cfg
  ******************************************************************************
  * @attention
  * 
  * 
  ******************************************************************************
  */
	
#include "bsp_pwr_cfg.h"


void PWRGPIOConfig(void)
{		
    /*定义一个GPIO_InitTypeDef类型的结构体*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /*开启GPIOB的外设时钟*/
    RCC_AHB1PeriphClockCmd( PWR_RCC_PERIPHPORT, ENABLE); 

    /*选择要控制的GPIOA引脚*/															   
    GPIO_InitStructure.GPIO_Pin = PWRPIN;	

    /*设置要控制的GPIOA引脚为输出模式*/	
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;

    /*设置引脚速率为50MHz */   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

    /*设置引脚模式为通用推挽输出*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 

    /*设置引脚模式无上拉*/
    GPIO_InitStructure.GPIO_PuPd   = GPIO_PuPd_UP;  

    /*调用库函数，初始化GPIOA*/
    GPIO_Init(PWRPORT, &GPIO_InitStructure);		  

    /* 关闭电源	*/
    //PWR_OFF();
	PWR_ON();
}





