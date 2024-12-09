#pragma once
#include <iostream>
#include "database.hpp"
// #include <limits>      // For std::numeric_limits<std::streamsize>::max()

class Menu
{
public:
    void displayMainMenu();
    void displayPlayMenu();
    void displayRulesMenu();
    void displayLoginMenu();
    void displaySignInMenu();
    void displaySignUpMenu();
};