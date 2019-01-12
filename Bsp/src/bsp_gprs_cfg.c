
  
#include "bsp_gprs_cfg.h"
#include "string.h"
#include "includes.h"

void GPRS_Close(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//关机要先将 RING/DCD/TXD/RXD ,设置为低电平输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	//RING/DCD/TXD/RXD置低
	GPIO_ResetBits(GPIOD, GPIO_Pin_5|GPIO_Pin_6); 
	GPIO_ResetBits(GPIOB, GPIO_Pin_6|GPIO_Pin_7);
	
	//shutdowm 高电平有效
//	GPIO_SetBits(GPIOD, GPIO_Pin_11);
//	Delay_10ms(100);
//	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
//	
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
	
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);
	GPIO_SetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(600);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);
	
//	//增加PC7作为电源控制，1为开电源，0为关电源
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
//	GPIO_Init(GPIOC,&GPIO_InitStructure); 
//	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	
}

void GPRS_Config(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	
	//开关PD7 5秒高脉冲启动3G ,PD11 高电平关闭3G关闭
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_11; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	//RING/DCD/TXD/RXD置低
	GPIO_ResetBits(GPIOD, GPIO_Pin_5|GPIO_Pin_6); 
	GPIO_ResetBits(GPIOB, GPIO_Pin_6|GPIO_Pin_7);
	
//	//增加PC7作为电源控制，1为开电源，0为关电源
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
//	GPIO_Init(GPIOC,&GPIO_InitStructure); 
//	GPIO_SetBits(GPIOC,GPIO_Pin_7);
//	Delay_10ms(50);
	
	//时序开关ON/OFF,SHUTDOWM管脚
//	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
//	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
//	Delay_10ms(1000);
//	GPIO_SetBits(GPIOD, GPIO_Pin_7);
//	Delay_10ms(100);
	
	//released HW_SHUTDOWN
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
	//时序开关ON/OFF
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);
	GPIO_SetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(600);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);

}

