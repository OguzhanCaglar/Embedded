#include "terminal.h"

char sUartReceiveMessage[mUartRxBufferSize];

const char* sEntryMessage = "Welcome to Discovery Board!\n$ ";

const char* sUnknownCommandMessage = "Unknown command!";

const sCommand CommandTable[mCommandsNumber] =
{
	{ "help", 		eCommandHelp, 			fPrintHelpMessage, 	"Print Help Message"},
	{ "led 1 on", 	eCommandGreenLedOn, 	fHandleLed, 		"Turn on the green led"},
	{ "led 1 off", 	eCommandGreenLedOff, 	fHandleLed, 		"Turn off the green led"},
	{ "led 2 on", 	eCommandOrangeLedOn, 	fHandleLed, 		"Turn on the orange led"},
	{ "led 2 off", 	eCommandOrangeLedOff, 	fHandleLed, 		"Turn off the orange led"},
	{ "led 3 on", 	eCommandRedLedOn, 		fHandleLed, 		"Turn on the red led"},
	{ "led 3 off", 	eCommandRedLedOff, 		fHandleLed, 		"Turn off the red led"},
	{ "led 4 on", 	eCommandBlueLedOn, 		fHandleLed, 		"Turn on the blue led"},
	{ "led 4 off", 	eCommandBlueLedOff, 	fHandleLed, 		"Turn off the blue led"},
	{ "reset", 		eCommandReset, 			fResetSystem, 		"Resets the system"},
};

uint8_t currentCommand;

void fProcessCommand(char command[])
{
	currentCommand = eCommandStart;

	for(int i = 0; i < mCommandsNumber; i++)
	{
		if(strcmp(command, CommandTable[i].commandName) == 0)
		{
			currentCommand = CommandTable[i].command;
			CommandTable[i].command_function();
			break;
		}
	}

	if(currentCommand == eCommandStart)
	{
		currentCommand = eCommandUnknown;
		fPrintUnknownMessage();
	}
}

void fPrintHelpMessage(void)
{
	char buffer[128];

	for(int i = 0; i < mCommandsNumber; i++)
	{
		sprintf(buffer, "%-10s : %s\r\n", CommandTable[i].commandName, CommandTable[i].commandInfo);
		HAL_UART_Transmit(&huart4, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
	}
}

void fPrintUnknownMessage(void)
{
	HAL_UART_Transmit(&huart4, (uint8_t *)sUnknownCommandMessage, strlen(sUnknownCommandMessage), HAL_MAX_DELAY);
}

void fResetSystem(void)
{
	HAL_NVIC_SystemReset();
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






















