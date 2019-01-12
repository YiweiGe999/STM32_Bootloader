	/******************** (C) COPYRIGHT YiweiGe  ********************

  ******************************************************************************
  */
	
#include "bsp_key_cfg.h"

u8 s_funtionkey_state = IDLE;
static bool IsButtonPressdown(void);


void BSP_KeyInit(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
	GPIO_InitTypeDef KEY_strPortConfig;
	
	RCC_APB2PeriphClockCmd(KEY_RCC_PERIPHPORT, ENABLE); 	
	
	KEY_strPortConfig.GPIO_Pin = KEYPIN; 
	KEY_strPortConfig.GPIO_Mode = GPIO_Mode_IPU; 
	KEY_strPortConfig.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(KEYPORT, &KEY_strPortConfig);
	
	/* If you want to use exit interrupt,please define USE_EXTI_TRG_MORNITOR.*/
	#ifdef USE_EXTI_TRG_MORNITOR
	
	
	/*���������˿ڣ�PC����ʱ��*/
	RCC_APB2PeriphClockCmd(KEY_RCC_PERIPHPORT, ENABLE); 	
	
	KEY_strPortConfig.GPIO_Pin = KEYPIN; 
	KEY_strPortConfig.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	KEY_strPortConfig.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(KEYPORT, &KEY_strPortConfig);

	/* Enable AFIO clock */
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	 /* Connect EXTI0 Line to PA.03 pin */
	 GPIO_EXTILineConfig(EXIT_PORT_SOURCE, KEYPIN);



	
		EXTI_InitStructure.EXTI_Line = EXTI_Line4;;
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);

		/* Enable and set EXTI4 Interrupt to the lowest priority */
		NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	#endif
}



/*******************************************************************************
 * ����: IsButtonPressdown()
 * ����: ��ⰴ���Ƿ񱻰���
 *       
 * �β�: keytype -> ����������
 *      
 * ����: 0
 * ˵��: ��
 ******************************************************************************/
static bool IsButtonPressdown(void)
{
	u8 i = 0;
	if (KEY_ON == GPIO_ReadInputDataBit(KEYPORT,KEYPIN)) 
	{
		do
		{
				if(KEY_ON == GPIO_ReadInputDataBit(KEYPORT,KEYPIN))
				{
					i++;
				}
		}while(i>=5);
		return true;
	} 
	else 
	{
		return false;
	}
}


#ifdef USE_EXTI_TRG_MORNITOR
/*******************************************************************************
 * ����: CheckFuntionKeyState()
 * ����: ��⹦�ܼ���״̬
 *       
 * �β�: ��
 *      
 * ����: ����״̬
 * ˵��: ״̬��������ⰴ�� ���10ms�Ķ�ʱ�ж�ɨ���ǹؼ�
 ******************************************************************************/
t_KeyStateType BSP_CheckKeyState(void)
{

	static unsigned char s_funtionkeytime = 0;	/* ����״̬��ʱ */
  t_KeyStateType keystate_return = IDLE;		/* ����״̬����ֵ */

	keystate_return = s_funtionkey_state;
	
  return keystate_return;
}




#elif (defined(USE_SCAN_KEY_MONITOR))
/*******************************************************************************
 * ����: CheckFuntionKeyState()
 * ����: ��⹦�ܼ���״̬
 *       
 * �β�: ��
 *      
 * ����: ����״̬
 * ˵��: ״̬��������ⰴ�� ���15ms�Ķ�ʱ�ж�ɨ���ǹؼ�
 ******************************************************************************/
t_KeyStateType BSP_CheckKeyState(void)
{

	static unsigned char s_funtionkeytime = 0;	/* ����״̬��ʱ */
    t_KeyStateType keystate_return = IDLE;		/* ����״̬����ֵ */

	switch (s_funtionkey_state) 
	{
		case IDLE:
				if (IsButtonPressdown()) 
				{
				/* ��⵽�������� ������һ״̬*/
					s_funtionkey_state = VERILY;
				}
				else
				{
					s_funtionkey_state = IDLE;
				}
			
		break;
				
		case VERILY:
				if (IsButtonPressdown()) 
				{
				/* 10ms�ٽ������������������ϣ�������һ״̬������ص���һ״̬ */
					s_funtionkey_state = CLICK_ONCE;
				}
				else 
				{
					s_funtionkey_state = IDLE;
				}
		break;
				
		case CLICK_ONCE:
        if (!IsButtonPressdown()) 
				{                    
							/* ��⵽�����ͷţ�˵��һ�ε�����ɣ�������˫��״̬*/    
					s_funtionkey_state = CLICK_TWICE;
					s_funtionkeytime = 0;
        } 
				else if(++s_funtionkeytime >= LONGPRESSTIME) 
				{
					s_funtionkeytime = 0;
					s_funtionkey_state = CLICK_LONG;
					keystate_return = CLICK_LONG;
                
				} 
				else
				{
					
				}
		break;
				
		case CLICK_TWICE:
        if (IsButtonPressdown()) 
				{   					                  

					s_funtionkey_state = OVER_TIME_STATE; 		 
					s_funtionkeytime = 0;	             
                
				} 
				else if (++s_funtionkeytime >= INTERVAL) 
				{
						/* �������ʱ��û�а�����ȷ����һ�������¼� */
						s_funtionkeytime = 0;
						keystate_return = CLICK_ONCE;
						s_funtionkey_state = IDLE;
				}             
			
		break;
		case OVER_TIME_STATE:
				/* ���û���ͷŵڶ��ΰ�����һֱ��� 10ms���жϼ��һ�� */
				if (!IsButtonPressdown()) 
				{
					 s_funtionkey_state = IDLE;
					 keystate_return = CLICK_TWICE;
				}
			
		break;
				
		case CLICK_LONG:
				if (!IsButtonPressdown()) 
				{
					s_funtionkey_state = IDLE;
					keystate_return = IDLE;
				}
	
		break;
				
		default:
		break;
	}
    return keystate_return;
}

#endif




