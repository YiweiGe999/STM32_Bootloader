#include "stm32f10x_flash_api.h"

void FlashInit(void)
{
	FLASH_Unlock();
	FLASH_ErasePage(FLASH_DATA_PAGE);
	FLASH_ITConfig(FLASH_IT_EOP, ENABLE);
	
}

FLASH_Status FlashWriteData(uint32_t Address,uint16_t *wBuffer,uint16_t lenth)
{
	FLASH_Status status = FLASH_COMPLETE;
	while(lenth--)
	{
		while(FLASH_GetFlagStatus(FLASH_FLAG_BSY));
		status = FLASH_ProgramHalfWord(Address,*(wBuffer++));
		if(status != FLASH_COMPLETE)
		{
			return status;
		}
		Address = Address+2;
	}
	
	return status;
}

