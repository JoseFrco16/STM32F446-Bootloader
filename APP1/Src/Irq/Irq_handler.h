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
#define TRUE 1u
#define FALSE 0u

/* Private variables ---------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Boot Irq flag getter
 */
uint8_t Irq_GetBootFlag(void);

/**
 * @brief Error Handler
 */
void Error_Handler(void);

/**
 * @brief SysTick Handler
 *        Increments uwTick variable used by HAL_Delay.
 */
void SysTick_Handler(void);

/**
 * @brief EXTI15_10 Handler
 *        Handle button Gpio
 */
void EXTI15_10_IRQHandler(void);

#endif /* IRQ_HANDLER__H */
