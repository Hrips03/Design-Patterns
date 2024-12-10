#include "eventHandler.hpp"

eventHandler::eventHandler(Controller* controller)
    : m_contrPtr(controller), m_user(nullptr) { // Initialize user to nullptr
    displayMainMenu();
}

void eventHandler::handleMenuChoice() {
    getMenuChoice();

    if (choice == "Easy" || choice == "easy" || choice == "Medium" || choice == "medium" || choice == "Hard" || choice == "hard") {
        IGrid* grid = selector(choice);
        grid->generateGrid();
        grid->draw();
        gameCycle(grid, choice);
    } else {
        if (choice == "Play" || choice == "play")
            displayLoginMenu();
        else if (choice == "Sign In" || choice == "sign in")
            displaySignInMenu();
        else if (choice == "Sign up" || choice == "sign up")
            displaySignUpMenu();
        else if (choice == "continue" || choice == "guest")
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

void eventHandler::getMenuChoice()
{
    std::cout << "Enter your choice: ";
    std::getline(std::cin, choice);
    // std::cout << "Your choice is " << choice << std::endl
    //           << std::endl;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
}

void eventHandler::gameCycle(IGrid* grid, const std::string& difficulty) {
    std::string input;
    bool end = false;
    Timer timer;
    timer.start();

    while (true) {
        if (end) {
            std::cout << "Game over!\n";
            displayMainMenu();
            break;
        }

        std::cout << "Time: " << timer.getElapsedTime() << "\n";
        std::cout << "Enter a cell position (e.g., 'mark 8 7', 'reveal 3 5', 'unmark 6 4' or type 'exit' to go back): ";

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
        } else if (command == "unmark") {
            grid->unmarkCell(row, col);
        } else if (command == "reveal") {
            end = grid->revealCell(row, col);

            if (grid->checkWin()) {
                std::cout << "Congratulations! You've revealed all the non-mine cells. You win!" << std::endl;

                if (m_user) { 
                    std::string elapsedTime = timer.getElapsedTime();
                    if (m_user->getBestScore(difficulty) == "00:00" || elapsedTime < m_user->getBestScore(difficulty)) {
                        m_user->setBestScore(difficulty, elapsedTime);
                        SQLiteDB::getInstance()->updateBestScore(m_user->getUsername(), difficulty, elapsedTime);
                    }
                }
                displayMainMenu();
                break;
            }
        } else {
            std::cout << "Invalid command. Please use 'mark', 'unmark', or 'reveal'." << std::endl;
        }
        grid->draw();
    }
}
