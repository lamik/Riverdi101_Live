/*
 * led_task.h
 *
 *  Created on: Jun 8, 2022
 *      Author: mateu
 */

#ifndef APPLICATION_USER_CORE_LED_TASK_LED_TASK_H_
#define APPLICATION_USER_CORE_LED_TASK_LED_TASK_H_

#include "cmsis_os.h"

void StartLedTask(void const * argument);

osStatus LedSendMessage(uint8_t LedMessage);

void LedTaskLoop(void);

#endif /* APPLICATION_USER_CORE_LED_TASK_LED_TASK_H_ */
