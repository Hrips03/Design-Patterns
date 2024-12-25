#include "menu.hpp"
#include <iostream>

Menu::Menu(const std::vector<std::string> &options, float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        exit(1);
    }

    selectedIndex = -1;
    for (size_t i = 0; i < options.size(); ++i)
    {
        sf::Text option;
        option.setFont(font);
        option.setString(options[i]);
        option.setCharacterSize(20);
        option.setFillColor(sf::Color::White);
        option.setPosition(width / 2.0f - option.getGlobalBounds().width / 2.0f, height / 4.0f + i * 50.0f);
        menuOptions.push_back(option);
    }
}

void Menu::draw(sf::RenderWindow &window)
{
    for (auto &option : menuOptions)
    {
        window.draw(option);
    }
}

int Menu::getOptionClicked(const sf::Vector2f &mousePos)
{
    for (size_t i = 0; i < menuOptions.size(); ++i)
    {
        if (menuOptions[i].getGlobalBounds().contains(mousePos))
        {
            return i; 
        }
    }
    return -1; 
}

void Menu::highlightOption(const sf::Vector2f &mousePos)
{
    for (size_t i = 0; i < menuOptions.size(); ++i)
    {
        if (menuOptions[i].getGlobalBounds().contains(mousePos))
        {
            menuOptions[i].setFillColor(sf::Color::Red);
        }
        else
        {
            menuOptions[i].setFillColor(sf::Color::White);
        }
    }
}
