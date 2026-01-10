/**
 ******************************************************************************
 * @file       Pal_Mngr.c
 * @brief      Platform Abstraction Manager
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef PAL_MNGR__H
#define PAL_MNGR__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Gpio.h"
#include "Mcu.h"
#include "Uart.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Platform abstraction manager initialization
 */
void Pal_Init(void);

#endif /* PAL_MNGR__H */
