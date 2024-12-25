#pragma once
#include <iostream>
#include "database.hpp"
#include "user.hpp"
#include "../view/Grid.hpp"

class Menu
{
public:
    void displayMainMenu();
    void displayPlayMenu();
    void displayRulesMenu();
    void displayLoginMenu();
    void displaySignInMenu();
    void displaySignUpMenu();
    Grid* selector(const std::string& difficulty);
};