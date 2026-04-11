/**
 ******************************************************************************
 * @file       Ota.h
 * @brief      Over-The-Air (OTA)
 * @details    Remote embedded software update through OTA.
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef OTA__H
#define OTA__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include <stdio.h>
#include "Types.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum{
	UART,
}Ota_InterfaceType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Copy Flash from OTA to APP region
 */
void Ota_CopyFlashFromOtaToApp( void );

#endif /* OTA__H */
