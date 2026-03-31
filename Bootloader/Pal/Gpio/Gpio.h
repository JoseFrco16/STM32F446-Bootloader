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

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef enum{
	USER_LED = 0,
	TOTAL_GPIO,
}Gpio_PinType;

typedef enum{
	HIGH = 0,
	LOW,
}Gpio_PinStateType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Gpio initialization required for bootloader
 */
void Gpio_Init();

/**
 * @brief Gpio Write
 * @param[in] Pin Pin to set
 * @param[in] State State to be set
 */
void Gpio_SetPin( Gpio_PinType Pin, Gpio_PinStateType State );

#endif /* GPIO__H */
