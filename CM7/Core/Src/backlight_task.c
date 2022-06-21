/*
 * backlight_task.c
 *
 *  Created on: Jun 14, 2022
 *      Author: mateu
 */
#include "main.h"
#include "backlight_task.h"

#include "FreeRTOS.h"
#include "cmsis_os.h"

#include "tim.h"

static osMessageQId backlightReceiveQueueHandle;

static osEvent BacklightReadMessage(void)
{
	osEvent Status;

	Status = osMessageGet(backlightReceiveQueueHandle, 0);
	return Status;
}

void StartBacklightTask(void const * argument)
{

	osEvent BacklightQueueStatus;

	osMessageQDef(backlightQueue, 32, int);
	backlightReceiveQueueHandle = osMessageCreate(osMessageQ(backlightQueue), NULL);

	for(;;)
	{
		BacklightQueueStatus = BacklightReadMessage();

		if(BacklightQueueStatus.status == osEventMessage)
		{
			uint16_t NewPWMValue = (uint16_t) BacklightQueueStatus.value.v;

			if(NewPWMValue > 999)
			{
				NewPWMValue = 999;
			}

			if(NewPWMValue < 100)
			{
				NewPWMValue = 100;
			}

			__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, NewPWMValue);

		}
	}
}

osStatus BacklightSendMessage(int BacklightMessage)
{
	osStatus Status;

	Status = osMessagePut(backlightReceiveQueueHandle, BacklightMessage, osWaitForever);
	return Status;
}
