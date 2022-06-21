#include <gui/screen1_screen/Screen1View.hpp>


extern "C"
{
#include "main.h"
#include "tim.h"
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    sliderBacklightPWM.setValue(__HAL_TIM_GET_COMPARE(&htim15, TIM_CHANNEL_1));
    sliderBacklightPWM.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::LedOnClicked()
{
	presenter->TurnOnLed();
}

void Screen1View::LedOffClicked()
{
	presenter->TurnOffLed();
}

void Screen1View::sliderBacklightPWMChanged(int NewValue)
{
	// uint16_t NewValue = sliderBacklightPWM.getValue();
	presenter->ChangePWMValue(NewValue);
}

void Screen1View::SetPwmValue(int CurrentPwmValue)
{
	CurrentPwmValue /= 10;
	Unicode::snprintf(textAreaPWMValueBuffer, TEXTAREAPWMVALUE_SIZE, "%d", CurrentPwmValue);
	textAreaPWMValue.invalidate();
}
