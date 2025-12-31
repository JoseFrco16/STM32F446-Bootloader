/**
 ******************************************************************************
 * @file       Ver.h
 * @brief      Bootloader version manager
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef VER__H
#define VER__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/
#define FW_VERSION_MAJOR   1
#define FW_VERSION_MINOR   0
#define FW_VERSION_PATCH   0

#define FW_VERSION_U32 ((FW_VERSION_MAJOR << 16) | \
                        (FW_VERSION_MINOR << 8)  | \
                        (FW_VERSION_PATCH))

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
extern uint32_t Ver_FwVersion;

/* Public function prototypes ------------------------------------------------*/

#endif /* VER__H */
