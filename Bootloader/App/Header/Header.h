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

/* Define --------------------------------------------------------------------*/
/* Application's header address */
#define HEADER_APP_HEADER_START_ADDR 0x8008000u
/* Application's address */
#define HEADER_APP_START_ADDR 0x8008400u
/* Application's magic number */
#define HEADER_MAGIC_NUMBER 0xF00Du

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief  Magic number from header getter
 * @return magic_number Magic number from header interface
 */
uint32_t Header_GetMagicNumber( void );

#endif /* HEADER__H */
