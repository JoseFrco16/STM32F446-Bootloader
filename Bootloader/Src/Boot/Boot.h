/**
 ******************************************************************************
 * @file       Boot.h
 * @brief      Manage jump to target application
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT__H
#define BOOT__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Manage jumps between applications
 */
void Boot_ManageBootloaderJumps(void);

void Boot_LedSequence(void);

#endif /* BOOT__H */
