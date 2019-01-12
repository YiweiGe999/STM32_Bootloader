#include "TASK_cfg.h"

#include "ALED_int.h"

#include "AKEY_int.h"

FUNC_aStatusType Func_aStatus[NBR_enuSTATUS];
TASK_aTimeType Task_aTime[NBR_enuTask];
Task_aActiveType Task_aActiveStatus[NBR_enuTask];
Func FUNC_aTaskName[NBR_enuTask] = 
{

	&ALED_vidTask,
	&AKEY_vidTask,



};



const u16 Task_aTimeConfg[NBR_enuTask] = 
{
	PRIODS_enu10ms,
	PRIODS_enu15ms,

};

void FUNC_vidStatusInit(void)
{

	u8 i;

	for(i = 0; i< NBR_enuSTATUS; i++)
	{
		Func_aStatus[i] = 0;
	}
}




void TASK_vidActiveStatusInit(void)
{

	u8 i;

	for(i = 0; i< NBR_enuSTATUS; i++)
	{
		Task_aActiveStatus[i] = TASK_enuDeactive;
	
  }


}

void TASK_vidTimeInit(void)
{

	u8 i;

	for(i = 0; i< NBR_enuSTATUS; i++)
	{
		Task_aTime[i] = 0;
	
  }

	
}

void TASK_vidInit(void)
{


	FUNC_vidStatusInit();
	
	TASK_vidTimeInit();

	TASK_vidActiveStatusInit();
}

void TASK_vidTimeOut(void)
{

	u8 i;
	for(i = 0; i<NBR_enuTask; i++)
	{
		Task_aTime[i]++;
		if(Task_aTime[i] >= Task_aTimeConfg[i])
		{
			Task_aTime[i] = 0;
			Task_aActiveStatus[i] = TASK_enuActive;
		}
	
	}

}

void TASK_vidScheduler(void)
{

	u8 i;
	for(i=0; i<NBR_enuTask; i++)
	{
		if(Task_aActiveStatus[i] ==  TASK_enuActive)
		{
			(*FUNC_aTaskName[i])();
			Task_aActiveStatus[i] = TASK_enuDeactive;
		}
		else
		{
		}
	
	}

}

