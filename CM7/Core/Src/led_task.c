/*
 * led_task.c
 *
 *  Created on: Jun 8, 2022
 *      Author: mateu
 */
#include "main.h"
#include "led_task.h"

#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "gpio.h"

static osMessageQId usrLedQueueHandle;

static osEvent LedReadMessage(void)
{
	osEvent Status;

	Status = osMessageGet(usrLedQueueHandle, 0);
	return Status;
}

void LedTaskLoop(void)
{
	osEvent LedQueueStatus;

	osMessageQDef(usrLedQueue, 4, uint8_t);
	usrLedQueueHandle = osMessageCreate(osMessageQ(usrLedQueue), NULL);

	for(;;)
	{
		LedQueueStatus = LedReadMessage();

		if(LedQueueStatus.status == osOK)
		{
			switch(LedQueueStatus.value.v)
			{
			case 0:
					HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, GPIO_PIN_SET);
				break;

			case 1:
					HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, GPIO_PIN_RESET);
				break;
			}
		}

	}
}

osStatus LedSendMessage(uint8_t LedMessage)
{
	osStatus Status;

	Status = osMessagePut(usrLedQueueHandle, LedMessage, osWaitForever);
	return Status;
}
