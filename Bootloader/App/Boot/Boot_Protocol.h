/**
 ******************************************************************************
 * @file       Boot_Protocol.h
 * @brief      Manage bootloader communication protocol.
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT_PROTOCOL__H
#define BOOT_PROTOCOL__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/*
 * @brief     Send Bootloader Reply through current interface
 * @param[in] Data Optional data to be sent
 * @param[in] Length Data's length
 * @param[in] Error Error status to be sent with ACK
 */
void Boot_SendReply( uint8_t* Data, uint8_t Length, Boot_StatusType Error );

#endif /* BOOT_PROTOCOL__H */
