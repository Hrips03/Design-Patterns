#include "eventHandler.hpp"

eventHandler::eventHandler(Controller *controller) : m_contrPtr(controller)
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
    getMenuChoice();

    if (choice == "Easy" || choice == "easy" || choice == "Medium" || choice == "medium" || choice == "Hard" || choice == "hard") {
        IGrid* grid = selector(choice);
        grid->draw();
        processInput(grid);
    } 
    else
    {
        if (choice == "Play" || choice == "play")
            displayPlayMenu();
        else if (choice == "Rules" || choice == "rules")
            displayRulesMenu();
        else if (choice == "back" || choice == "Back")
            displayMainMenu();
        else if (choice == "exit" || choice == "Exit")
            m_contrPtr->exit();
        else
            std::cout << "Invalid choice, try again." << std::endl;
    }
}

void eventHandler::processInput(IGrid* grid) {
    std::string input;
    while (true) {
        std::cout << "Enter a cell position (e.g., 'mark 8 7', 'reveal 3 5' or type 'exit' to go back): ";
        
        std::string command;
        int row, col;

        std::cin >> command;

        if (command == "exit") {
           displayMainMenu();
           break;
        }

        std::cin >> row >> col;
        if (command == "mark") {
            grid->markCell(row, col); 
        } else if (command == "reveal") {
            grid->revealCell(row, col); 
        } else {
            std::cout << "Invalid command. Please use 'mark' or 'reveal'." << std::endl;
        }

        grid->draw();  
    }
}