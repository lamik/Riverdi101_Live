/*
 * backlight_task.h
 *
 *  Created on: Jun 14, 2022
 *      Author: mateu
 */

#ifndef APPLICATION_USER_CORE_BACKLIGHT_TASK_H_
#define APPLICATION_USER_CORE_BACKLIGHT_TASK_H_


#include "cmsis_os.h"

void StartBacklightTask(void const * argument);

osStatus BacklightSendMessage(int BacklightMessage);
int BacklightPwmValueReadMessage(int *PwmValue);

#endif /* APPLICATION_USER_CORE_BACKLIGHT_TASK_H_ */
