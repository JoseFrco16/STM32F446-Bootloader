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
#include "Boot_ProtocolTypes.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/*
 * @brief     Execute commands received though current interface
 * @param[in] RxProtocolFrame Bootloader Rx Protocol Frame
 * @return    finish_flag Flag to indicate bootloader end
 */
uint8_t Boot_ExecuteCmd( Boot_RxProtocolType* RxProtocolFrame );

#endif /* BOOT_HANDLERS__H */
