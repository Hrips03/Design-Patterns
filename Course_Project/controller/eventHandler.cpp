#include "eventHandler.hpp"
#include "controller.hpp"
#include "../view/selector.hpp" // Only includes the declaration

eventHandler::eventHandler(Controller *controller) : contrPtr(controller)
{
    displayMainMenu();
}

void eventHandler::getMenuChoice()
{
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "Your choice is " << choice << std::endl
              << std::endl;
}

void eventHandler::handleMenuChoice()
{
    if (choice == "Easy" || choice == "easy" || choice == "Medium" || choice == "medium" || choice == "Hard" || choice == "hard")
        selector(choice); // Uses the selector function
    else
    {
        getMenuChoice();
        if (choice == "Play" || choice == "play")
            displayPlayMenu();
        else if (choice == "Rules" || choice == "rules")
            displayRulesMenu();
        else if (choice == "back" || choice == "Back")
            displayMainMenu();
        else if (choice == "exit" || choice == "Exit")
            contrPtr->exit();
        else
            std::cout << "Invalid choice, try again." << std::endl;
    }
}
