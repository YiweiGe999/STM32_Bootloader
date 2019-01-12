#ifndef __FLASH_API_H
#define __FLASH_API_H

#include "stm32f10x_flash.h"
#include "main.h"


#define FLASH_BASE_ADDR		((uint32_t)0x08000000)
#define FLASH_PAGE_SIZE    	((uint16_t)0x800)
#define FLASH_DATA_PAGE		((uint32_t)(4*FLASH_PAGE_SIZE+FLASH_BASE_ADDR))
#define APP_START_ADDR		((uint32_t)(5*FLASH_PAGE_SIZE+FLASH_BASE_ADDR))



void FlashInit(void);
FLASH_Status FlashWriteData(uint32_t Address,uint16_t *wBuffer,uint16_t lenth);

#endif 



