/**
 ******************************************************************************
 * @file       Header_AppHeaderRegs.h
 * @brief      Application header registers
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef HEADER_APPHEADERFLAGS__H
#define HEADER_APPHEADERFLAGS__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/
/* Application's magic number */
#define HEADER_MAGIC_NUMBER 0xF00Du

/* Typedef -------------------------------------------------------------------*/
typedef struct
{
	uint32_t ota_flag;
    uint32_t magic;
    uint32_t size;
    uint32_t crc;
    uint32_t version;
} Header_RegsType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/


#endif /* HEADER_APPHEADERFLAGS__H */
