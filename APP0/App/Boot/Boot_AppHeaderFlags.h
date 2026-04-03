/**
 ******************************************************************************
 * @file       Boot_AppHeaderFlags.h
 * @brief      Application header flags used by bootloader
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT_APPHEADERFLAGS__H
#define BOOT_APPHEADERFLAGS__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/
/* Application's header address */
#define BOOT_APP_HEADER_START_ADDR 0x8008000u
/* Application's address */
#define BOOT_APP_START_ADDR 0x8008400u
/* Application's magic number */
#define BOOT_MAGIC_NUMBER 0xF00Du

/* Typedef -------------------------------------------------------------------*/
typedef struct
{
	uint32_t ota_flag;
    uint32_t magic;
    uint32_t size;
    uint32_t crc;
    uint32_t version;
} Boot_HeaderFlagsType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/


#endif /* BOOT_APPHEADERFLAGS__H */
