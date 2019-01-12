#include "TASK_cfg.h"
#include "ALED_int.h"
#include "AKEY_int.h"

void ALED_vidInit(void)
{
	HFIC_LedInit();
	ALED_vidWorkMode(ALED_enuALL_OFF);
	
	
}

void ALED_vidWorkMode(ALED_enuMode enuLedMode)
{
	switch(enuLedMode)
	{
		case 	ALED_enuALL_OFF:
			HFIC_LedSwitch(LED0,LED_OFF);
			HFIC_LedSwitch(LED1,LED_OFF);
			break;
		
		case	ALED_enuALL_ON:
			HFIC_LedSwitch(LED0,LED_ON);
			HFIC_LedSwitch(LED1,LED_ON);
			break;
		
		case	ALED_enuLED0_ON:
			HFIC_LedSwitch(LED0,LED_ON);
			HFIC_LedSwitch(LED1,LED_OFF);
			break;
		
		case  ALED_enuLED1_ON:
			HFIC_LedSwitch(LED1,LED_ON);
			HFIC_LedSwitch(LED0,LED_OFF);
			break;
		
		default:
			break;
	}
}


void ALED_vidTask(void)
{
	static u32 u32StaticLED0 = 0;
	if(Func_aStatus[BTN_enuSTATUS] == BTN_CLICK_ONCE)
	{
			Func_aStatus[LED_enuSTATUS]=ALED_enuLED0_ON ;
			
	}
	else if(Func_aStatus[BTN_enuSTATUS] == BTN_CLICK_TWICE)
	{

		Func_aStatus[LED_enuSTATUS]= ALED_enuLED1_ON ;
	}
	else if(Func_aStatus[BTN_enuSTATUS] == BTN_CLICK_LONG)
	{
		Func_aStatus[LED_enuSTATUS]= ALED_enuALL_ON ;
		

	}
	else  if(Func_aStatus[BTN_enuSTATUS] == BTN_IDLE)
	{
		//Func_aStatus[LED_enuSTATUS]= ALED_enuALL_OFF;
	}

	ALED_vidWorkMode(Func_aStatus[LED_enuSTATUS]);
}

