#ifndef __AKEY_INT_H
#define __AKEY_INT_H

#include "HFIC.h"

#define BTN_IDLE   			0			/* ��������״̬ */
#define BTN_VERILY 			1 			/* ��������ȷ��״̬ */
#define BTN_CLICK_ONCE  	2 			/* ��������״̬ */
#define BTN_CLICK_TWICE     3    		/* ����˫��״̬ */
#define BTN_CLICK_LONG   	4 			/* ��������״̬ */
#define BTN_TEMP_STATE		5			/* ����״̬ ��״̬�ڲ�ʹ�ã������ⲿ�� */

void AKEY_vidInit(void);


void AKEY_vidTask(void);


#endif





