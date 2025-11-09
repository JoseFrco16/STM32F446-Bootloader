/**
 ******************************************************************************
 * @file       Irq_handler.c
 * @brief      Handlers used by Bootloader Irqs
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef IRQ_HANDLER__H
#define IRQ_HANDLER__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

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

#endif /* IRQ_HANDLER__H */
