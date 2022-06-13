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

void LedTaskLoop(void)
{
	for(;;)
	{
		HAL_GPIO_TogglePin(USR_LED_GPIO_Port, USR_LED_Pin);
		osDelay(300);
		// Infinite Loop
	}
}
