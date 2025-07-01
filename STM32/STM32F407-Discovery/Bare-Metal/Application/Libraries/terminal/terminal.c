#include "terminal.h"

char sUartReceiveMessage[mUartRxBufferSize];
const char* sEntryMessage = "Welcome to Discovery Board!\n===== Supported Commands =====\n- help\n- Led <PIN> ON/OFF\n$ ";
const char* sHelpMessage = "\n====== USAGE ======\n- help\n- Led <PIN> ON/OFF\n===================";
const char* sUnknownCommandMessage = "Unknown command!";

const sCommand CommandTable[mCommandsNumber] =
{
	{ "help", 		eCommandHelp, 			fPrintHelpMessage},
	{ "led 1 on", 	eCommandGreenLedOn, 	fHandleLed},
	{ "led 1 off", 	eCommandGreenLedOff, 	fHandleLed},
	{ "led 2 on", 	eCommandOrangeLedOn, 	fHandleLed},
	{ "led 2 off", 	eCommandOrangeLedOff, 	fHandleLed},
	{ "led 3 on", 	eCommandRedLedOn, 		fHandleLed},
	{ "led 3 off", 	eCommandRedLedOff, 		fHandleLed},
	{ "led 4 on", 	eCommandBlueLedOn, 		fHandleLed},
	{ "led 4 off", 	eCommandBlueLedOff, 	fHandleLed},
	{ "",			eCommandUnknown,		fPrintUnknownMessage}
};

uint8_t currentCommand;

void fProcessCommand(char command[])
{
	for(int i = 0; i < mCommandsNumber; i++)
	{
		if(strcmp(command, CommandTable[i].commandName) == 0)
		{
			currentCommand = CommandTable[i].command;
			CommandTable[i].command_function();
			break;
		}
	}
}

void fPrintHelpMessage(void)
{
	HAL_UART_Transmit(&huart4, (uint8_t *)sHelpMessage, strlen(sHelpMessage), HAL_MAX_DELAY);
}

void fPrintUnknownMessage(void)
{
	HAL_UART_Transmit(&huart4, (uint8_t *)sUnknownCommandMessage, strlen(sUnknownCommandMessage), HAL_MAX_DELAY);
}

void fHandleLed(void)
{
	switch(currentCommand)
	{

		case eCommandGreenLedOn:
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			break;

		case eCommandGreenLedOff:
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			break;

		case eCommandOrangeLedOn:
			HAL_GPIO_WritePin(LED_ORANGE_GPIO_Port, LED_ORANGE_Pin, GPIO_PIN_SET);
			break;

		case eCommandOrangeLedOff:
			HAL_GPIO_WritePin(LED_ORANGE_GPIO_Port, LED_ORANGE_Pin, GPIO_PIN_RESET);
			break;

		case eCommandRedLedOn:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			break;

		case eCommandRedLedOff:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			break;

		case eCommandBlueLedOn:
			HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
			break;

		case eCommandBlueLedOff:
			HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_RESET);
			break;
		default :
			break;
	}
}






















