/**
 ******************************************************************************
 * @file       Boot_ProtocolTypes.h
 * @brief      Bootloader Protocol Types
 * @name       JoseFrco16
 *******************************************************************************/

#ifndef BOOT_PROTOCOLTYPES__H
#define BOOT_PROTOCOLTYPES__H

/* Includes ------------------------------------------------------------------ */
#include <stdint.h>
#include "Uart.h"

/* Define --------------------------------------------------------------------*/
/* Bootloader TX header ( SOF + ACK + Status + Length ) length */
#define BOOT_TX_HEADER_LENGTH 4u
/* Bootloader RX header ( SOF + Cmd + Length ) length */
#define BOOT_RX_HEADER_LENGTH 3u

/* Bootloader maximum TX data length */
#define BOOT_MAX_TX_DATA_LENGTH ( UART_TX_BUFFER - BOOT_TX_HEADER_LENGTH )
/* Bootloader maximum RX data length */
#define BOOT_MAX_RX_DATA_LENGTH ( UART_RX_BUFFER - BOOT_RX_HEADER_LENGTH )
/* Bootloader Start of Frame Mark */
#define BOOT_HEADER_SOF 0xAAu
/* Bootloader Rx Header Length */
#define BOOT_RX_HEADER 3u
/* Bootloader Acknowledge Mark */
#define BOOT_ACK 0x06u
#define BOOT_NACK 0x15u

/* Typedef -------------------------------------------------------------------*/
typedef enum{
	PING = 0,
	BOOT_VERSION,
	DEVICE_INFO,
	ERASE_FLASH,
	WRITE_FLASH,
	COMPUTE_CRC,
	AUTHENTICATE,
	UNLOCK,
	JUMP_TO_APPLICATION,
	MCU_RESET,
	CMD_TOTAL,
}Boot_CmdType;

typedef struct __attribute__((packed)){
	uint8_t Sof;
	Boot_CmdType Cmd;
	uint8_t Length;
	uint8_t Data[ BOOT_MAX_RX_DATA_LENGTH ];
}Boot_RxProtocolType;

typedef struct __attribute__((packed)){
	uint8_t Sof;
	uint8_t Ack;
	uint8_t Status;
	uint8_t Length;
	uint8_t Data[ BOOT_MAX_TX_DATA_LENGTH ];
}Boot_TxProtocolType;

typedef enum{
	OK = 0,
	ERROR_RX_FRAME,
	ERROR_CRC,
	ERROR_MEMORY_ADDRESS
} Boot_StatusType;

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/


#endif /* BOOT_PROTOCOLTYPES__H */
