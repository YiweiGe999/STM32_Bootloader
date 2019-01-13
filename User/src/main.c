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
  HFIC_UsartInit();
}




int main(void)
{
	SysInit();
	
	printf("\n");
	printf("\n");
	printf(" ********************************************\n");
	printf(" *                                          *\n");
	printf(" *        System initialized complete!      *\n");
	printf(" *                                          *\n");
	printf(" ********************************************\n");
	printf("\n");
	printf("\n");
	while(1)
	{
		TASK_vidScheduler();
	}

}


