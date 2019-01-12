
  
#include "bsp_bt_cfg.h"
#include "includes.h"

void Bluetooth_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
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

	//������������
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);
	GPIO_ResetBits(GPIOD,GPIO_Pin_4);
	//��λ�������ߣ��͵�ƽ��λ
	GPIO_SetBits(GPIOD, GPIO_Pin_0);

	//�����ڲ����ڿ���
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);

	Delay_10ms(100);// 1s
	printf("\r\nconfig name set SLCV100\r\n");
	Delay_10ms(100);// 1s
	printf("\r\nconfig name set SLCV100\r\n");
	
}

/*********************************************END OF FILE**********************/
