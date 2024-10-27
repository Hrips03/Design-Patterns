#pragma once
#include "menu.hpp"
#include "../view/selector.hpp"
// Forward declaration of Controller
class Controller;

class eventHandler : public Menu
{
    std::string choice;
    Controller* contrPtr;

public:
    eventHandler(Controller* controller);
    void getMenuChoice();
    void handleMenuChoice();
};
