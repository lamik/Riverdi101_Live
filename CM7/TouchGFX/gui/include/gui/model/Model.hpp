#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    virtual void TurnOnLed();
    virtual void TurnOffLed();

    virtual void ChangeBacklightIntesity(int NewValue);

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
