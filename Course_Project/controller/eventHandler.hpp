#pragma once
#include "menu.hpp"
#include "controller.hpp"
#include "../view/selector.hpp"
#include "../model/logic.hpp"

class Controller;

class eventHandler : public Menu
{
    std::string choice;
    Controller* m_contrPtr;

public:
    explicit eventHandler(Controller* controller);
    void getMenuChoice();
    void handleMenuChoice();
    void processInput(IGrid* grid);

};

