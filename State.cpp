#include <iostream>

class State
{
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void changeChannel(int chan) = 0;
    virtual void TurnOnVolume(int vol) = 0;
    virtual void TurnOffVolume(int vol) = 0;
    virtual ~State() = default;
};

//Context
class TV
{
    State *state;

public:
    TV();
    void setState(State *st) { state = st; }
    void on() { state->on(); };
    void off() { state->off(); };
    void changeChannel(int chan) { state->changeChannel(chan); };
    void TurnOnVolume(int vol) { state->TurnOnVolume(vol); };
    void TurnOffVolume(int vol) { state->TurnOffVolume(vol); };
};

class OffState : public State
{
    TV *tv;

public:
    OffState(TV *tv) : tv(tv) {}

    void on() override;

    void off() override
    {
        std::cout << "TV is already OFF.\n";
    }

    void changeChannel(int chan) override
    {
        std::cout << "Turn on the TV first to change channels.\n";
    }

    void TurnOnVolume(int vol) override
    {
        std::cout << "Turn on the TV first to adjust volume.\n";
    }

    void TurnOffVolume(int vol) override
    {
        std::cout << "Turn on the TV first to adjust volume.\n";
    }
};

class OnState : public State
{
    TV *tv;

public:
    OnState(TV *tv) : tv(tv) {}

    void on() override
    {
        std::cout << "TV is already ON.\n";
    }

    void off() override
    {
        std::cout << "Turning TV OFF.\n";
        tv->setState(new OffState(tv));
    }

    void changeChannel(int chan) override
    {
        std::cout << "Changing channel to " << chan << ".\n";
    }

    void TurnOnVolume(int vol) override
    {
        std::cout << "Turning volume up by " << vol << ".\n";
    }

    void TurnOffVolume(int vol) override
    {
        std::cout << "Turning volume down by " << vol << ".\n";
    }
};

void OffState::on()
{
    std::cout << "Turning TV ON.\n";
    tv->setState(new OnState(tv));
}

TV::TV() { setState(new OffState(this)); }

int main()
{
    TV *my_tv = new TV();
   
    my_tv->on();
    my_tv->on();

    my_tv->changeChannel(11);
    my_tv->TurnOnVolume(6);
    my_tv->TurnOffVolume(4);

    my_tv->off();
    my_tv->changeChannel(22);

    return 0;
}
