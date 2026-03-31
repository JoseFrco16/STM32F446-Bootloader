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
#include "Boot_ProtocolTypes.h"

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/*
 * @brief     Send Bootloader Command through current interface
 * @param[in] Data Optional data to be sent
 * @param[in] Length Data's length
 * @param[in] Error Error status to be sent with ACK
 */
void Boot_SendCmd( uint8_t* Data, uint8_t Length, Boot_StatusType Error );

/*
 * @brief     Read Bootloader Command through current interface
 * @return    RxProtocol Memory adddress of Rx Protocol data
 */
Boot_RxProtocolType* Boot_ReadCmd( void );

#endif /* BOOT_PROTOCOL__H */
