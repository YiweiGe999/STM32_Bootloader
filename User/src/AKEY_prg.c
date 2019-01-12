#include "AKEY_int.h"
#include "TASK_cfg.h"
#include "ALED_int.h"


void AKEY_vidInit(void)
{
	HFIC_KeyInit();
}


void AKEY_vidTask(void)
{

	Func_aStatus[BTN_enuSTATUS] = HFIC_enuKeyPress();
}




