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
static osMessageQId backlightPwmValueToGuiQueueHandle;

static osEvent BacklightReadMessage(void)
{
	osEvent Status;

	Status = osMessageGet(backlightReceiveQueueHandle, 0);
	return Status;
}

static osStatus BacklightPwmValueSendMessage(uint16_t PwmValueMessage)
{
	osStatus Status;

	Status = osMessagePut(backlightPwmValueToGuiQueueHandle, PwmValueMessage, 0);
	return Status;
}

void StartBacklightTask(void const * argument)
{

	osEvent BacklightQueueStatus;
	osStatus BacklightPwmValueToGuiQueue;

	osMessageQDef(backlightQueue, 1, int);
	backlightReceiveQueueHandle = osMessageCreate(osMessageQ(backlightQueue), NULL);

	osMessageQDef(backlightPwmValueToGuiQueue, 1, uint16_t);
	backlightPwmValueToGuiQueueHandle = osMessageCreate(osMessageQ(backlightPwmValueToGuiQueue), NULL);

	BacklightPwmValueToGuiQueue = BacklightPwmValueSendMessage(__HAL_TIM_GET_COMPARE(&htim15, TIM_CHANNEL_1));

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

			if(NewPWMValue < 40)
			{
				NewPWMValue = 40;
			}

			__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, NewPWMValue);

			BacklightPwmValueToGuiQueue = BacklightPwmValueSendMessage(__HAL_TIM_GET_COMPARE(&htim15, TIM_CHANNEL_1));
		}

	}
}

osStatus BacklightSendMessage(int BacklightMessage)
{
	osStatus Status;

	Status = osMessagePut(backlightReceiveQueueHandle, BacklightMessage, osWaitForever);
	return Status;
}

int BacklightPwmValueReadMessage(int *PwmValue)
{
	osEvent Status;

	Status = osMessageGet(backlightPwmValueToGuiQueueHandle, 0);

	if(Status.status == osEventMessage)
	{
		*PwmValue = Status.value.v;
		return 1;
	}
	else
	{
		return 0;
	}

}
