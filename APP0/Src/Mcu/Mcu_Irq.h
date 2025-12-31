/**
 ******************************************************************************
 * @file       Mcu_Irq.c
 * @brief      Handlers used by Bootloader Irqs
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef MCU_IRQ__H
#define MCU_IRQ__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Error Handler
 */
void Error_Handler(void);

/**
 * @brief SysTick Handler
 *        Increments uwTick variable used by HAL_Delay.
 */
void SysTick_Handler(void);

#endif /* MCU_IRQ__H */
