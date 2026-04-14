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

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Flash initialization
 */
void Flash_Init( void );

/**
 * @brief
 */
void Flash_Unlock(void);

/**
 * @brief
 */
void Flash_Lock(void);

/**
 * @brief
 */
void Flash_Write();

/**
 * @brief
 */
void Flash_Read();

/**
 * @brief
 */
void Flash_Erase();

#endif /* FLASH__H */
