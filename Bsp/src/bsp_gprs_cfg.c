
  
#include "bsp_gprs_cfg.h"
#include "string.h"
#include "includes.h"

void GPRS_Close(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//�ػ�Ҫ�Ƚ� RING/DCD/TXD/RXD ,����Ϊ�͵�ƽ���
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	//RING/DCD/TXD/RXD�õ�
	GPIO_ResetBits(GPIOD, GPIO_Pin_5|GPIO_Pin_6); 
	GPIO_ResetBits(GPIOB, GPIO_Pin_6|GPIO_Pin_7);
	
	//shutdowm �ߵ�ƽ��Ч
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
	
//	//����PC7��Ϊ��Դ���ƣ�1Ϊ����Դ��0Ϊ�ص�Դ
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
	
	//����PD7 5�����������3G ,PD11 �ߵ�ƽ�ر�3G�ر�
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
	//RING/DCD/TXD/RXD�õ�
	GPIO_ResetBits(GPIOD, GPIO_Pin_5|GPIO_Pin_6); 
	GPIO_ResetBits(GPIOB, GPIO_Pin_6|GPIO_Pin_7);
	
//	//����PC7��Ϊ��Դ���ƣ�1Ϊ����Դ��0Ϊ�ص�Դ
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
//	GPIO_Init(GPIOC,&GPIO_InitStructure); 
//	GPIO_SetBits(GPIOC,GPIO_Pin_7);
//	Delay_10ms(50);
	
	//ʱ�򿪹�ON/OFF,SHUTDOWM�ܽ�
//	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
//	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
//	Delay_10ms(1000);
//	GPIO_SetBits(GPIOD, GPIO_Pin_7);
//	Delay_10ms(100);
	
	//released HW_SHUTDOWN
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
	//ʱ�򿪹�ON/OFF
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);
	GPIO_SetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(600);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
	Delay_10ms(100);

}

