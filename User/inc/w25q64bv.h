#ifndef _W25Q64BV_H__
#define _W25Q64BV_H__

#include "stdint.h"
#include "bsp_spi.h"
/* Serial flash memory instruction set table*/
#define FLASH_READ_ID							0x9f
#define FLASH_W25Q64BV_ID					0x4017

#define FLASH_WRITE_ENABLE				0x06
#define FLASH_WRITE_DISABLE				0x04

#define FLASH_READ_STATUS_REG_1		0x05
#define FLASH_READ_STATUS_REG_2   0x35
#define FLASH_WRITE_STATUS_REG    0x01
#define FLASH_READ_DATA						0x03

#define FLASH_PAGE_PROGRAM				0x02
#define FLASH_BLOCK_ERASE_64K			0xd8
#define FLASH_BLOCK_ERASE_32K     0x52
#define FLASH_SECTOR_ERASE_4K			0x20
#define FLASH_CHIP_ERASE          0x60



void W25q64bv_Init(void);
void W25q64bv_WriteEnable(void);
void W25q64bv_WriteDisable(void);
uint8_t W25q64bv_ReadID(void);
uint8_t W25q64bv_ReadRegStatus(uint8_t *rbuff,uint8_t cmd);
uint8_t W25q64bv_ReadData(uint8_t *rbuff,uint32_t addr,uint16_t length);
uint8_t W25q64bv_WriteRegStatus(uint8_t cmd);
uint8_t W25q64bv_WriteData(uint8_t *wbuff,uint32_t addr,uint16_t length);
uint8_t W25q64bv_SectorErase(void);
uint8_t W25q64bv_BlockErase(uint8_t cmd);

#endif 

