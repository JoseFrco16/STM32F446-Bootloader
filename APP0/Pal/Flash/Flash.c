/**
 ******************************************************************************
 * @file       Flash.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Flash.h"
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public Functions  ---------------------------------------------------------*/
void Flash_Init( void )
{
    HAL_FLASH_Lock();
}

Flash_ErrorType Flash_Unlock( void )
{
	HAL_StatusTypeDef hal_status;
	Flash_ErrorType flash_status = FLASH_NOK;

	hal_status = HAL_FLASH_Unlock();

	if( hal_status == HAL_OK )
	{
		flash_status = FLASH_OK;
	}

	return flash_status;
}

void Flash_Lock( void )
{
    HAL_FLASH_Lock();
}

Flash_ErrorType Flash_Write( Flash_ProgramType TypeProgram, uint32_t Address, uint64_t Data )
{
	HAL_StatusTypeDef hal_status;
	Flash_ErrorType flash_status = FLASH_NOK;

	hal_status = HAL_FLASH_Program( TypeProgram, Address, Data );

	if( hal_status == HAL_OK )
	{
		flash_status = FLASH_OK;
	}

	return flash_status;
}

uint32_t Flash_Read( uint32_t Address )
{
	return *(uint32_t*)Address;
}

Flash_ErrorType Flash_Erase( Flash_SectorType Sector, uint8_t NumberSectors )
{
	HAL_StatusTypeDef hal_status;
	Flash_ErrorType flash_status = FLASH_NOK;
    FLASH_EraseInitTypeDef erase;
    uint32_t sector_error;

    erase.TypeErase = FLASH_TYPEERASE_SECTORS;
    erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;
    erase.Sector = Sector;
    erase.NbSectors = NumberSectors;

    hal_status = HAL_FLASHEx_Erase(&erase, &sector_error);

	if( hal_status == HAL_OK )
	{
		flash_status = FLASH_OK;
	}

	return flash_status;
}
/* Private Functions  ---------------------------------------------------------*/
