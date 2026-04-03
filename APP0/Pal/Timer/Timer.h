/**
 ******************************************************************************
 * @file       Timer.c
 * @brief      Timer configurations
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef TIMER__H
#define TIMER__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Wait the ticks passed as input
 * @param[in]   Delay Minimum delay used to block MCU execution.
 */
void Timer_Delay( uint32_t Delay );

#endif /* TIMER__H */
