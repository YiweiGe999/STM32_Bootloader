	/******************** (C) COPYRIGHT Hi-Target  ********************
 * �ļ���  ��bsp_pwr_cfg.c
 * ����    ����ԴоƬ����    
 * ʵ��ƽ̨��V100 RTK
 * ��汾  ��V1.0.0
 * ����    ��
 * ����    ��
 * �޸�ʱ��: 2015-3-6
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
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /*����GPIOB������ʱ��*/
    RCC_AHB1PeriphClockCmd( PWR_RCC_PERIPHPORT, ENABLE); 

    /*ѡ��Ҫ���Ƶ�GPIOA����*/															   
    GPIO_InitStructure.GPIO_Pin = PWRPIN;	

    /*����Ҫ���Ƶ�GPIOA����Ϊ���ģʽ*/	
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;

    /*������������Ϊ50MHz */   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

    /*��������ģʽΪͨ���������*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 

    /*��������ģʽ������*/
    GPIO_InitStructure.GPIO_PuPd   = GPIO_PuPd_UP;  

    /*���ÿ⺯������ʼ��GPIOA*/
    GPIO_Init(PWRPORT, &GPIO_InitStructure);		  

    /* �رյ�Դ	*/
    //PWR_OFF();
	PWR_ON();
}





