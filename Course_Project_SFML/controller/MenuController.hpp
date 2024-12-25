#pragma once
#include "../view/menu.hpp"
#include "../view/inputBox.hpp"
#include <iostream>
#include "../model/database.hpp"
#include "../model/user.hpp"

class MenuController
{
    User* m_user = nullptr;
    std::string m_difficulty;
public:
    std::vector<int> setMenu();
    std::vector<std::string> getUserInfo();
};