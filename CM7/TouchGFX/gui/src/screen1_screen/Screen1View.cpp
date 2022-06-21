#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
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
