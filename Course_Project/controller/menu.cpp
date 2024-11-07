#include "menu.hpp"

void Menu::displayMainMenu()
{
    std::cout << "Welcome to the Main Menu! Please make a choice.\n\n";
    std::cout << "Menu\n\n";
    std::cout << "Play\n";
    std::cout << "Rules\n";
    std::cout << "Exit\n\n";
}

void Menu::displayPlayMenu()
{
    std::cout << "Choose difficulty\n\n";
    std::cout << "Easy\n";
    std::cout << "Medium\n";
    std::cout << "Hard\n\n";
    std::cout << "back\n\n";
}

void Menu::displayRulesMenu()
{
    std::cout << "Rules\n\n";
    std::cout << "All non-mine cells must be\nopened without opening a mine.\n\n";
    std::cout << "back\n\n";
}


