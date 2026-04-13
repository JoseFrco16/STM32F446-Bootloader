/**
 ******************************************************************************
 * @file       Header.h
 * @brief      App/Boot Header Interface Driver
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef HEADER__H
#define HEADER__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/
/* Application's header address */
#define HEADER_APP_HEADER_START_ADDR 0x8008000u
/* Application's address */
#define HEADER_APP_START_ADDR 0x8008400u

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief     Ota flag from header setter
 */
void Header_SetOtaFlag( void );

#endif /* HEADER__H */
