/**
 ******************************************************************************
 * @file       Flash.c
 * @brief      Flash Platform Abstraction Layer
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef FLASH__H
#define FLASH__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum
{
	PROGRAM_BYTE = 0,
	PROGRAM_HALFWORD,
	PROGRAM_WORD,
	PROGRAM_DOUBLEWORD,
} Flash_ProgramType;

typedef enum
{
	SECTOR_0 = 0,
	SECTOR_1,
	SECTOR_2,
	SECTOR_3,
	SECTOR_4,
	SECTOR_5,
	SECTOR_6,
	SECTOR_7,
} Flash_SectorType;

typedef enum
{
	FLASH_OK = 0,
	FLASH_NOK,
} Flash_ErrorType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Flash initialization
 */
void Flash_Init( void );

/**
 * @brief Flash operations unlock
 */
Flash_ErrorType Flash_Unlock(void);

/**
 * @brief Flash operations lock
 */
void Flash_Lock(void);

/**
 * @brief Flash write
 * @param[in] TypeProgram Flash program type
 * @param[in] Address Flash address
 * @param[in] Data Data to be written
 * @return Flash write error
 */
Flash_ErrorType Flash_Write( Flash_ProgramType TypeProgram, uint32_t Address, uint64_t Data );

/**
 * @brief Flash read
 * @param[in] Address Address to read
 * @return Data Data read from address
 */
uint32_t Flash_Read( uint32_t Address );

/**
 * @brief Flash erase
 * @param[in] Sector Sector to erase
 * @param[in] NumberSectors Number of sector
 * @return Flash erase error
 */
Flash_ErrorType Flash_Erase( Flash_SectorType Sector, uint8_t NumberSectors );

#endif /* FLASH__H */
