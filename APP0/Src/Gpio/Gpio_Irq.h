/**
 ******************************************************************************
 * @file       Gpio_Irq.c
 * @brief      Handlers used by Bootloader Irqs
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef GPIO_IRQ__H
#define GPIO_IRQ__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/
#define TRUE 1u
#define FALSE 0u

/* Typedef -------------------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief Boot Irq flag getter
 */
uint8_t Irq_GetBootFlag(void);

/**
 * @brief EXTI15_10 Handler
 *        Handle button Gpio
 */
void EXTI15_10_IRQHandler(void);

#endif /* GPIO_IRQ__H */
