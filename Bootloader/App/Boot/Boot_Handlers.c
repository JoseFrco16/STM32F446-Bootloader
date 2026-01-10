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
#include "Types.h"
#include "stm32f4xx_hal.h"

/* Define --------------------------------------------------------------------*/
#define BOOT_APP_START_ADDR 0x08008000u

/* Enum  ----------------------------------------------------------------------*/
enum Boot_Status{
	OK = 0,
	ERROR_GENERIC,
	ERROR_CRC,
	ERROR_MEMORY_ADDRESS
};

/* Typedef -------------------------------------------------------------------*/
typedef void (*pAppRestHandler)(void);
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
static void Boot_JumpToAppHandler( void );

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
	[ JUMP_TO_APPLICATION ] = Boot_CmdMcuResetHandler,
	[ MCU_RESET ] = Boot_CmdMcuResetHandler,
};

/* Public Functions  ---------------------------------------------------------*/
void Boot_ExecuteCmd( Boot_CmdType Cmd )
{
	uint8_t error;

	if( ( Cmd >= CMD_TOTAL ) || ( Boot_CmdHandlerPtr[ Cmd ] == NULL ) )
	{
		// NACK
	}
	else
	{
		Boot_CmdHandlerPtr[ Cmd ]();
	}
}


/* Private Functions  ---------------------------------------------------------*/
static void Boot_CmdPingHandler( void )
{
	Boot_SendReply( 0u, 0u, OK );
}

static void Boot_CmdVersionHandler( void )
{
	uint32_t version = Ver_GetVersion();

	Boot_SendReply( version, 4u, OK );
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
	Boot_SendReply( 0u, 0u, OK );
	/* TODO: Wrap this function in Pal */
	NVIC_SystemReset();
}

static void Boot_CmdJumpToAppHandler( void )
{
	/* TODO: Move this to PAL */
	uint32_t appStack = *(volatile uint32_t*) BOOT_APP_START_ADDR;
	uint32_t appResetHandler = *(volatile uint32_t*) (BOOT_APP_START_ADDR + 4);

	HAL_RCC_DeInit();
	HAL_DeInit();

	/* Disable SysTick */
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	/* Set vector table */
	SCB->VTOR = BOOT_APP_START_ADDR;

	/* Set Main Stack Pointer */
	__set_MSP(appStack);

	/* Send ACK */
	Boot_SendReply( 0u, 0u, OK );

	/* Jump to Reset Handler of App0 */
	pAppRestHandler JumpToApplication = (pAppRestHandler) appResetHandler;
	JumpToApplication();
}


