/***********************************************************************************************
*

*
*
*
*
*
***********************************************************************************************/

#include "bsp_spi.h"
#include "main.h"




void Bsp_SpiInit(void)
{

	SPI_InitTypeDef BSP_SPI1_InitStructure;
	GPIO_InitTypeDef  BSP_SPI1_CS_InitStructure;
	GPIO_InitTypeDef  BSP_SPI1_GPIO_InitStructure;



	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	
	BSP_SPI1_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	BSP_SPI1_GPIO_InitStructure.GPIO_Pin = BSP_SPI1_CLK | BSP_SPI1_MISO | BSP_SPI1_MOSI;
	BSP_SPI1_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&BSP_SPI1_GPIO_InitStructure);


	BSP_SPI1_CS_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	BSP_SPI1_CS_InitStructure.GPIO_Pin = BSP_SPI1_CS;
	BSP_SPI1_CS_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&BSP_SPI1_CS_InitStructure);


//	BSP_SPI1_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
//	BSP_SPI1_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
//	BSP_SPI1_InitStructure.SPI_CPOL = SPI_CPOL_Low;
//	BSP_SPI1_InitStructure.SPI_CRCPolynomial = 0x07;
//	BSP_SPI1_InitStructure.SPI_DataSize = SPI_DataSize_8b;
//	BSP_SPI1_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
//	BSP_SPI1_InitStructure.SPI_Mode = SPI_Mode_Master;
//	BSP_SPI1_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
//	BSP_SPI1_InitStructure.SPI_NSS = SPI_NSS_Soft;
	
	SPI_StructInit(&BSP_SPI1_InitStructure);
	SPI_Init(SPI1, &BSP_SPI1_InitStructure);
	
	SPI_Cmd(SPI1, ENABLE);
	
	//SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_TXE, ENABLE);
	Bsp_Spi_CsCtrl(BSP_SPI_CS_LOW);
	Delay_ms(1);
	Bsp_Spi_CsCtrl(BSP_SPI_CS_HIGH);
	
	
}

void Bsp_Spi_CsCtrl(uint status)
{

	if(BSP_SPI_CS_HIGH == status)
	{
		GPIO_SetBits(GPIOA, BSP_SPI1_CS);
	}
	else if(BSP_SPI_CS_LOW == status)
	{
		GPIO_ResetBits(GPIOA, BSP_SPI1_CS);
	}
}




