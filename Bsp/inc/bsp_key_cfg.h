/*******************************************************************************
Copyright 2011-2021 R&D, ZHD HI-TARGET, All Rights Reserved.
http://www.zhdgps.com/

工程名称 : RTK模块机V6
模块名称 : 按键控制模块
模块文件 : key.c key.h
实现功能 : 初始化按键所接GPIO，完成按键控制任务函数
备 	注 : 

----------------------------------原始版本----------------------------------
日期 : 2015/3/10
版本 : V1.0.0
作者 : RTK固件组/gch
功能 : 1、初始化按键所接GPIO，完成按键控制任务函数
说明 ：

*******************************************************************************/
#ifndef BSP_KEY_CFG_H
#define BSP_KEY_CFG_H
 
#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stm32f10x.h"
#include "stdbool.h"
/* 按键状态定义 */
typedef enum {

	IDLE = 0,			/* 按键空闲状态 */
	VERILY = 1,			/* 按键按下确认状态 */
	CLICK_ONCE = 2,		/* 按键单击状态 */
	CLICK_TWICE = 3,	/* 按键双击状态 */
	CLICK_LONG = 4,		/* 按键长按状态 */
	OVER_TIME_STATE = 5		/* 过度状态 此状态内部使用，不供外部检测 */
}t_KeyStateType;

#define INTERVAL         30     /* 单、双击的间隔时间数 */
#define LONGPRESSTIME    100    /* 长按时间数 */
	 
#define KEY_ON	0
#define KEY_OFF	1

#define EXIT_PORT_SOURCE		GPIO_PortSourceGPIOA		
#define KEYPORT                 GPIOA 
#define KEYPIN	                GPIO_Pin_4 
#define KEY_RCC_PERIPHPORT      RCC_APB2Periph_GPIOA

extern u8 s_funtionkey_state;


#define USE_SCAN_KEY_MONITOR  
//#define USE_EXTI_TRG_MORNITOR     

void BSP_KeyInit(void);
t_KeyStateType BSP_CheckKeyState(void);
#endif
