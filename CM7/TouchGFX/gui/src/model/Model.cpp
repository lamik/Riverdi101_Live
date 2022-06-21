#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
#include "led_task.h"
#include "backlight_task.h"
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::TurnOnLed()
{
	LedSendMessage(1);
}

void Model::TurnOffLed()
{
	LedSendMessage(0);
}

void Model::ChangeBacklightIntesity(int NewValue)
{
	BacklightSendMessage(NewValue);
}
