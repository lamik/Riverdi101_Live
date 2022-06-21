#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::TurnOnLed()
{
	model->TurnOnLed();
}

void Screen1Presenter::TurnOffLed()
{
	model->TurnOffLed();
}

void Screen1Presenter::ChangePWMValue(int NewValue)
{
	model->ChangeBacklightIntesity(NewValue);
}
