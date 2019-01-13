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
  NVIC_InitStructure.NVIC_IRQChannel = BSP_USART_IRQn;//串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化NVIC寄存器、

}




void BSP_UsartInit(void)
{
	

	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
 	
	RCC_APB2PeriphClockCmd(BSP_RCC_USART_PORT, ENABLE);
	RCC_APB2PeriphClockCmd(BSP_RCC_USART, ENABLE);	
	//USART1端口配置
  GPIO_InitStructure.GPIO_Pin = BSP_USART_TX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz


	GPIO_Init(BSP_USART_PORT,&GPIO_InitStructure); //初始化PA9，PA10
	
	GPIO_InitStructure.GPIO_Pin = BSP_USART_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz


	GPIO_Init(BSP_USART_PORT,&GPIO_InitStructure); //初始化PA9，PA10
	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate = BSP_USART_BUADRATE;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
	
	USART_Init(BSP_USART, &USART_InitStructure); //初始化串口1
	USART_Cmd(BSP_USART, ENABLE);  //使能串口1 
	USART_ClearFlag(BSP_USART, USART_IT_RXNE);
    //USART1 中断使能 
  USART_ITConfig(BSP_USART, USART_IT_RXNE, ENABLE);//开启相关中断
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
		/* 发送一个字节数据到USART1 */
		USART_SendData(BSP_USART, ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_TC) == RESET);		
	}
}

#if (defined(USE_MICRO_LIB))
 /**
  * @brief  重定向c库函数printf到USART1
  * @param  
  * @retval 
  */
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到USART1 */
		USART_SendData(BSP_USART, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_TC) == RESET);		
	
		return (ch);
}

 /**
  * @brief  重定向c库函数scanf到USART1
  * @param  
  * @retval 
  */
int fgetc(FILE *f)
{
		/* 等待串口1输入数据 */
		while (USART_GetFlagStatus(BSP_USART, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(BSP_USART);
}


#endif
