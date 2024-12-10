#pragma once
#include <iostream>
#include "database.hpp"
#include "user.hpp"

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