#ifndef TERMINAL_H
#define TERMINAL_H

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define mUartRxBufferSize		20
#define mCommandsNumber			10

#define LED_GREEN_Pin 			GPIO_PIN_12
#define LED_GREEN_GPIO_Port 	GPIOD
#define LED_ORANGE_Pin 			GPIO_PIN_13
#define LED_ORANGE_GPIO_Port 	GPIOD
#define LED_RED_Pin 			GPIO_PIN_14
#define LED_RED_GPIO_Port 		GPIOD
#define LED_BLUE_Pin 			GPIO_PIN_15
#define LED_BLUE_GPIO_Port 		GPIOD

void fProcessCommand(char command[]);
void fPrintHelpMessage(void);
void fPrintUnknownMessage(void);
void fHandleLed(void);

typedef enum{
	eCommandStart,

	eCommandHelp,
	eCommandGreenLedOn,
	eCommandGreenLedOff,
	eCommandOrangeLedOn,
	eCommandOrangeLedOff,
	eCommandRedLedOn,
	eCommandRedLedOff,
	eCommandBlueLedOn,
	eCommandBlueLedOff,


	eCommandUnknown,
	eCommandEnd
}eCommands;

typedef struct {
	const char* commandName;
	eCommands command;
	void (*command_function)(void);
}sCommand;

extern const sCommand CommandTable[mCommandsNumber];
extern char sUartReceiveMessage[mUartRxBufferSize];
extern const char* sEntryMessage;
extern const char* sHelpMessage;
extern uint8_t cUartReceive;
extern uint8_t iRxIndex;
extern UART_HandleTypeDef huart4;
extern uint8_t currentCommand;



#endif
