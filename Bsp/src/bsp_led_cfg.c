/******************** YIweiGe **************************************************

  *****************************************************************************/
#include "bsp_led_cfg.h"
	 /**
  * @brief  This function initialize LED
  * @param  нч
  * @retval нч
  */
void BSP_LedInit(void)
{


    GPIO_InitTypeDef  LED_strInitConfig;

    /* Initialize periph colck */
		RCC_APB2PeriphClockCmd(LED_RCC_PERIPHPORT, ENABLE); 								   
		LED_strInitConfig.GPIO_Pin = LED0 | LED1;
		LED_strInitConfig.GPIO_Mode=GPIO_Mode_Out_PP;
    /* Configure GPIO output port speed as 50MHz */   
    LED_strInitConfig.GPIO_Speed = GPIO_Speed_50MHz;

    /*Initialize GPIO configure */
    GPIO_Init(LED_PORT, &LED_strInitConfig);		  

}
	



void BSP_LedSwitch(u16 u16LedIdex,u8 u8Status)
{
	if(u8Status == LED_ON)
	{
		GPIO_ResetBits(LED_PORT,u16LedIdex);
	}
	else
	{
		GPIO_SetBits(LED_PORT,u16LedIdex);
	}
	
	
}
