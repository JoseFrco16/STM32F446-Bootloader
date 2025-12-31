/**
 ******************************************************************************
 * @file       Gpio.c
 * @brief      Gpio configurations
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef GPIO__H
#define GPIO__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Gpio_Irq.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Gpio initialization required for bootloader
 */
void Gpio_Init();

#endif /* GPIO__H */
