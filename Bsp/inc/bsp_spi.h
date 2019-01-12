#ifndef BSP_SPI_H__
#define BSP_SPI_H__

#include "main.h"

#define BSP_SPI1_CS			GPIO_Pin_4
#define	BSP_SPI1_CLK		GPIO_Pin_5
#define BSP_SPI1_MISO		GPIO_Pin_6
#define BSP_SPI1_MOSI		GPIO_Pin_7

#define BSP_SPI_FREQUENCE_1MHZ	1000000
#define BSP_SPI_FREQUENCE_10MHZ	10000000
#define BSP_SPI_FREQUENCE_50MHZ	50000000

#define BSP_SPI_CS_LOW 	0
#define BSP_SPI_CS_HIGH 1

void Bsp_SpiInit(void);
void Bsp_Spi_CsCtrl(uint status);
//uint8_t Bsp_Spi_ReadRegStatus(uint8_t *rbuff,uint8_t cmd);
//uint8_t Bsp_Spi_ReadData(uint32_t addr,uint16_t length);
//uint8_t Bsp_Spi_WriteReg(uint8_t cmd);

#endif
