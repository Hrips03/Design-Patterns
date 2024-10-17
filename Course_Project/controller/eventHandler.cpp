#include "eventHandler.hpp"

eventHandler::eventHandler()
{
    displayMainMenu();
    getMenuChoice();
    handleMenuChoice();
}

void eventHandler::getMenuChoice()
{
    std::cin >> choice;
    std::cout << "Your choice is " << choice << std::endl;
}

bool eventHandler::handleMenuChoice()
{
    if(choice == "Easy" || choice == "Medium" || choice == "Hard"){
        //draw the grid
        return true;
    }

    if (choice == "Play")
        displayPlayMenu();
    else if (choice == "Rules")
        displayRulesMenu();
    else if (choice == "back")
        displayMainMenu();
    else
        std::terminate;

    return false;
}