#include <iostream>

class Menu
{
public:
    void displayMainMenu();
    void displayPlayMenu();
    void displayRulesMenu();

    virtual bool handleMenuChoice() = 0;
};