#ifndef __TASK_CFG_H
#define __TASK_CFG_H

#include "type_name.h"

typedef void (*Func)();
typedef enum{


	TASK_enuDeactive = 0xFF,
	TASK_enuActive	= 0xAA,

}TASK_enuActiveType;

typedef enum{


	LED_enuSTATUS,
	BTN_enuSTATUS,

	NBR_enuSTATUS,
	
}FUNC_enuStatusType;

typedef enum{


	PRIODS_enu0ms = 0,
	PRIODS_enu1ms,
	PRIODS_enu2ms,
	PRIODS_enu3ms,
	PRIODS_enu4ms,
	PRIODS_enu5ms,
	PRIODS_enu6ms,
	PRIODS_enu7ms,
	PRIODS_enu8ms,
	PRIODS_enu9ms,
	PRIODS_enu10ms,
	PRIODS_enu11ms,
	PRIODS_enu12ms,
	PRIODS_enu13ms,
	PRIODS_enu14ms,
	PRIODS_enu15ms,
	PRIODS_enu16ms,
	PRIODS_enu17ms,
	PRIODS_enu18ms,
	PRIODS_enu19ms,
	PRIODS_enu20ms,

}TIME_enuType;

typedef enum{


	LED_enuTask,
	BTN_enuTask,

	NBR_enuTask,

}Task_enuType;

typedef u8 FUNC_aStatusType;
typedef u32 TASK_aTimeType;
typedef u8 Task_aActiveType;



extern FUNC_aStatusType Func_aStatus[NBR_enuSTATUS];
extern TASK_aTimeType Task_aTime[NBR_enuTask];
extern Task_aActiveType Task_aActiveStatus[NBR_enuTask];
extern Func FUNC_aTaskName[NBR_enuTask];

extern void FUNC_vidStatusInit(void);
extern void TASK_vidTimeInit(void);
extern void TASK_vidActiveStatusInit(void);
extern void TASK_vidInit(void);
extern void TASK_vidTimeOut(void);
extern void TASK_vidScheduler(void);



#endif


