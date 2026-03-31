/**
 ******************************************************************************
 * @file       Mcu.c
 * @brief      Mcu configurations
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef MCU__H
#define MCU__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include <Mcu_Irq.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Mcu initialization required for bootloader
 */
void Mcu_Init();

/**
 * @brief Jump to the indicated address
 */
void Mcu_JumpToApp( uint32_t AppAddress );

/**
 * @brief Mcu reset
 */
void Mcu_Reset();

#endif /* MCU__H */
