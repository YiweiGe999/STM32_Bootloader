#ifndef __AKEY_INT_H
#define __AKEY_INT_H

#include "HFIC.h"

#define BTN_IDLE   			0			/* 按键空闲状态 */
#define BTN_VERILY 			1 			/* 按键按下确认状态 */
#define BTN_CLICK_ONCE  	2 			/* 按键单击状态 */
#define BTN_CLICK_TWICE     3    		/* 按键双击状态 */
#define BTN_CLICK_LONG   	4 			/* 按键长按状态 */
#define BTN_TEMP_STATE		5			/* 过度状态 此状态内部使用，不供外部检 */

void AKEY_vidInit(void);


void AKEY_vidTask(void);


#endif





