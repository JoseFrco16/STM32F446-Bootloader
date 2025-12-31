/**
 ******************************************************************************
 * @file       Boot.h
 * @brief      Manage jump to target application
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT__H
#define BOOT__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Manage bootloader commands
 */
void Boot_ManageBootloaderCmd( int8_t cmd );

/**
 * @brief Manage bootloader led sequence
 */
void Boot_LedSequence(void);

#endif /* BOOT__H */
