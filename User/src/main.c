/*********************************************************************************************************
*
*
*
*
*
********************************************************************************************************/


#include "TASK_cfg.h"
#include "ALED_int.h"
#include "AKEY_int.h"
#include "stm32f10x.h"
#include "system_stm32f10x.h" 
#include "stm32f10x_conf.h"	 
#include "HFIC.h"



void SysInit(void)
{
	TASK_vidInit();
	SysTick_Init();
	ALED_vidInit();
	AKEY_vidInit();
}




int main(void)
{
	SysInit();
	while(1)
	{
		TASK_vidScheduler();

	}

}


