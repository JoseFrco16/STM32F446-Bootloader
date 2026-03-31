/**
 ******************************************************************************
 * @file       Boot.c
 * @name       JoseFrco16
 *******************************************************************************/

/* Includes ------------------------------------------------------------------ */
#include "Boot.h"
#include "Boot_Handlers.h"
#include "Boot_Protocol.h"
#include "Ver.h"
#include "Mcu.h"
#include "Types.h"

/* Define --------------------------------------------------------------------*/
#define BOOT_APP_START_ADDR 0x08008000u

/* Enum  ----------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
typedef void (*Boot_CmdHandler_t)(void);

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/*
 * @brief Ping Handler
 *        Command used to verify connection.
 *        It should return ACK + Boot Mode
 */
static void Boot_CmdPingHandler( void );

/*
 * @brief Version Handler
 *        It should return ACK + Version
 */
static void Boot_CmdVersionHandler( void );

/*
 * @brief Device Information Handler
 *        It should return ACK + Device Information
 */
static void Boot_CmdDeviceInfoHandler( void );

/*
 * @brief Erase Flash Handler
 *        It should return ACK
 */
static void Boot_CmdEraseFlashHandler( void );

/*
 * @brief Write Flash Handler
 *        It should return ACK
 */
static void Boot_CmdWriteFlashHandler( void );

/*
 * @brief Compute CRC Handler
 *        It should return ACK (CRC check Ok) or NACK (CRC check nok)
 */
static void Boot_CmdComputeCrcHandler( void );

/*
 * @brief Authenticate Handler
 */
static void Boot_CmdAuthenticateHandler( void );

/*
 * @brief Unlock MCU Handler
 */
static void Boot_CmdUnlockHandler( void );

/*
 * @brief MCU Reset Handler
 *        It should return ACK and reset MCU.
 */
static void Boot_CmdMcuResetHandler( void );

/*
 * @brief  Jump to application handler.
 *         It should return ACK and jump to application.
 */
static void Boot_CmdJumpToAppHandler( void );

/* Private variables ---------------------------------------------------------*/
Boot_CmdHandler_t Boot_CmdHandlerPtr[ CMD_TOTAL ] =
{
    [ PING ] = Boot_CmdPingHandler,
	[ BOOT_VERSION ] = Boot_CmdVersionHandler,
	[ DEVICE_INFO ] = Boot_CmdDeviceInfoHandler,
	[ ERASE_FLASH ] = Boot_CmdEraseFlashHandler,
	[ WRITE_FLASH ] = Boot_CmdWriteFlashHandler,
	[ COMPUTE_CRC ] = Boot_CmdComputeCrcHandler,
	[ AUTHENTICATE ] = Boot_CmdAuthenticateHandler,
	[ UNLOCK ] = Boot_CmdUnlockHandler,
	[ JUMP_TO_APPLICATION ] = Boot_CmdJumpToAppHandler,
	[ MCU_RESET ] = Boot_CmdMcuResetHandler,
};

/* Public Functions  ---------------------------------------------------------*/
uint8_t Boot_ExecuteCmd( Boot_RxProtocolType* RxProtocolFrame )
{
	uint8_t finish_flag = False;

	if( ( RxProtocolFrame == NULL ) ||
		( RxProtocolFrame->Cmd >= CMD_TOTAL ) ||
		( Boot_CmdHandlerPtr[ RxProtocolFrame->Cmd ] == NULL ) )
	{
		Boot_SendCmd( 0u, 0u, ERROR_RX_FRAME );
	}
	else
	{
		Boot_CmdHandlerPtr[ RxProtocolFrame->Cmd ]();
	}

	return finish_flag;
}


/* Private Functions  ---------------------------------------------------------*/
static void Boot_CmdPingHandler( void )
{
	Boot_SendCmd( 0u, 0u, OK );
}

static void Boot_CmdVersionHandler( void )
{
	uint32_t version = Ver_GetVersion();

	Boot_SendCmd( ( uint8_t* )version, 4u, OK );
}

static void Boot_CmdDeviceInfoHandler( void )
{

}

static void Boot_CmdEraseFlashHandler( void )
{

}

static void Boot_CmdWriteFlashHandler( void )
{

}

static void Boot_CmdComputeCrcHandler( void )
{

}

static void Boot_CmdAuthenticateHandler( void )
{

}

static void Boot_CmdUnlockHandler( void )
{

}

static void Boot_CmdMcuResetHandler( void )
{
	Boot_SendCmd( 0u, 0u, OK );
	Mcu_Reset();
}

static void Boot_CmdJumpToAppHandler( void )
{
	Boot_SendCmd( 0u, 0u, OK );
	Mcu_JumpToApp( BOOT_APP_START_ADDR );
}


