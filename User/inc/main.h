
#ifndef MAIN_H__
#define MAIN_H__


#ifdef __cplusplus
 extern "C" {
#endif


	 

#include "core_cm3.h"
#include "misc.h"
#include "stdint.h"
#include "stm32f10x.h"
#include "system_stm32f10x.h" 
#include "type_name.h" 
#include "stm32f10x_conf.h"	 
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

#define	Freqence_72MHz	72000000
//uint8_t boot_version[8]={0x57,0x59,0x57,0x31,0x30,0x30,0x30,0x30};

void Delay_ms(__IO uint32_t nTime);
void Systick_Init(void);

#endif
