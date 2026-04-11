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
 * @brief Set interface used by OTA update
 * @param[in] Interface Interface selected for the OTA
 */
void Ota_SetInterface( Ota_InterfaceType Interface );

/**
 * @brief Read Data from interface selected
 * @param[in] Data Data to read
 * @param[out] Length Length from Data
 */
void Ota_ReadInterface( uint8_t* Data, uint8_t Length );

/**
 * @brief Write Data from interface selected
 * @param[in] Data Data to write
 * @param[out] Length Length from Data
 */
void Ota_WriteInterface( uint8_t* Data, uint8_t Length );

/**
 * @brief Erase Flash region reserved to OTA updates
 */
void Ota_EraseFlashRegion( void );

/**
 * @brief Write the Flash region reserved to OTA updates
 * @param[in]  Data Data to be written in OTA Flash region
 * @param[out] Length Length of Data to be written in the operation
 */
void Ota_WriteFlashRegion( uint8_t* Data, uint8_t Length );

#endif /* OTA__H */
