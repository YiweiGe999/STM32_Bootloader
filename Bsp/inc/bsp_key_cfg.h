/*******************************************************************************
Copyright 2011-2021 R&D, ZHD HI-TARGET, All Rights Reserved.
http://www.zhdgps.com/

�������� : RTKģ���V6
ģ������ : ��������ģ��
ģ���ļ� : key.c key.h
ʵ�ֹ��� : ��ʼ����������GPIO����ɰ�������������
�� 	ע : 

----------------------------------ԭʼ�汾----------------------------------
���� : 2015/3/10
�汾 : V1.0.0
���� : RTK�̼���/gch
���� : 1����ʼ����������GPIO����ɰ�������������
˵�� ��

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
/* ����״̬���� */
typedef enum {

	IDLE = 0,			/* ��������״̬ */
	VERILY = 1,			/* ��������ȷ��״̬ */
	CLICK_ONCE = 2,		/* ��������״̬ */
	CLICK_TWICE = 3,	/* ����˫��״̬ */
	CLICK_LONG = 4,		/* ��������״̬ */
	OVER_TIME_STATE = 5		/* ����״̬ ��״̬�ڲ�ʹ�ã������ⲿ��� */
}t_KeyStateType;

#define INTERVAL         30     /* ����˫���ļ��ʱ���� */
#define LONGPRESSTIME    100    /* ����ʱ���� */
	 
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
