/**
 ******************************************************************************
 * @file       Boot.h
 * @brief      Manage jump to bootloader
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT__H
#define BOOT__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include <stdio.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Check bootloader request
 *        The application reset MCU in case of bootloader request
 */
void Boot_CheckBootRequest( void );

#endif /* BOOT__H */
