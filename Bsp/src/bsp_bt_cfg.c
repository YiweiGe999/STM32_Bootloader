
  
#include "bsp_bt_cfg.h"
#include "includes.h"

void Bluetooth_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 


//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; 
//	GPIO_Init(GPIOD,&GPIO_InitStructure); 
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
//	GPIO_Init(GPIOD,&GPIO_InitStructure); 

	//流控引脚拉低
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);
	GPIO_ResetBits(GPIOD,GPIO_Pin_4);
	//复位引脚拉高，低电平复位
	GPIO_SetBits(GPIOD, GPIO_Pin_0);

	//设置内部串口开关
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);

	Delay_10ms(100);// 1s
	printf("\r\nconfig name set SLCV100\r\n");
	Delay_10ms(100);// 1s
	printf("\r\nconfig name set SLCV100\r\n");
	
}

/*********************************************END OF FILE**********************/
