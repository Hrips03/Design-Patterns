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

void Menu::displayLoginMenu()
{
    std::cout << "      Sign In\n";
    std::cout << "      Sign Up\n";
    std::cout << "Continue without account\n\n";
    std::cout << "back\n\n";
}

void Menu::displaySignInMenu()
{
    std::string username;
    std::string password;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover newline
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    SQLiteDB* db = SQLiteDB::getInstance();
    if (db->checkCredentials(username, password))
        displayPlayMenu(); 
    else
        displayMainMenu();  
}

void Menu::displaySignUpMenu()
{
    std::string username;
    std::string password;
    std::string renterPassword;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover newline
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);
    std::cout << "Renter your password: ";
    std::getline(std::cin, renterPassword);
    while (password != renterPassword)
    {
        std::cout << "Passwords do not match. Reenter your password: ";
        std::getline(std::cin, renterPassword);
    }

    SQLiteDB* db = SQLiteDB::getInstance();
    if (db->addUser(username, password))
        displayPlayMenu();
    else
        displayMainMenu();
}
