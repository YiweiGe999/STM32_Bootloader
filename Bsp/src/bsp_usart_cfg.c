	/******************** *******************************************************
	*
	*
	*
	*
	* 
  *****************************************************************************/
  

#include "bsp_usart_cfg.h"
#include "string.h"
//#include <stdarg.h>


static void USARTx_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_IRQn;//����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��NVIC�Ĵ�����

}




void BSP_UsartInit(void)
{
	

	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
 	
	RCC_APB2PeriphClockCmd(BSP_RCC_USART_PORT, ENABLE);
	RCC_APB2PeriphClockCmd(BSP_RCC_USART, ENABLE);	
	//USART1�˿�����
  GPIO_InitStructure.GPIO_Pin = BSP_USART_TX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz


	GPIO_Init(BSP_USART_PORT,&GPIO_InitStructure); //��ʼ��PA9��PA10
	
	GPIO_InitStructure.GPIO_Pin = BSP_USART_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz


	GPIO_Init(BSP_USART_PORT,&GPIO_InitStructure); //��ʼ��PA9��PA10
	//USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = BSP_USART_BUADRATE;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
	
	USART_Init(BSP_USART, &USART_InitStructure); //��ʼ������1
	USART_Cmd(BSP_USART, ENABLE);  //ʹ�ܴ���1 
	USART_ClearFlag(BSP_USART, USART_IT_RXNE);
    //USART1 �ж�ʹ�� 
  USART_ITConfig(BSP_USART, USART_IT_RXNE, ENABLE);//��������ж�
	USARTx_NVIC_Config();
}



void BSP_UsartSendBlock(u8 *u8BlockData)
{
	u16 i = 0;
	u8 ch;
	while(((*u8BlockData)!='\0') && (i<256))
	{
		ch = *u8BlockData;
		u8BlockData++;
		i++ ;
		/* ����һ���ֽ����ݵ�USART1 */
		USART_SendData(BSP_USART, ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_TC) == RESET);		
	}
}

#if (defined(USE_MICRO_LIB))
 /**
  * @brief  �ض���c�⺯��printf��USART1
  * @param  
  * @retval 
  */
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ�USART1 */
		USART_SendData(BSP_USART, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_TC) == RESET);		
	
		return (ch);
}

 /**
  * @brief  �ض���c�⺯��scanf��USART1
  * @param  
  * @retval 
  */
int fgetc(FILE *f)
{
		/* �ȴ�����1�������� */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(BSP_USART);
}


#endif
