#ifndef __ALED_INT_H
#define __ALED_INT_H

#include "HFIC.h"

typedef enum{

	ALED_enuALL_OFF,
	ALED_enuALL_ON,
	ALED_enuLED0_ON,
	ALED_enuLED1_ON,
	ALED_enuNBR_MODE,
}ALED_enuMode;

extern void ALED_vidInit(void);
extern void ALED_vidWorkMode(ALED_enuMode enuLedMode);
extern void ALED_vidTask(void);


#endif


