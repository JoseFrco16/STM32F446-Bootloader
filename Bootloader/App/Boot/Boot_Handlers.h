/**
 ******************************************************************************
 * @file       Boot_Handlers.h
 * @brief      Bootloader comands handler
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT_HANDLERS__H
#define BOOT_HANDLERS__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum{
	PING = 0,
	BOOT_VERSION,
	DEVICE_INFO,
	ERASE_FLASH,
	WRITE_FLASH,
	COMPUTE_CRC,
	AUTHENTICATE,
	UNLOCK,
	JUMP_TO_APPLICATION,
	MCU_RESET,
	CMD_TOTAL,
}Boot_CmdType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/*
 * @brief     Execute commands received though current interface
 * @param[in] Cmd Command to execute
 */
void Boot_ExecuteCmd( Boot_CmdType Cmd );

#endif /* BOOT_HANDLERS__H */
