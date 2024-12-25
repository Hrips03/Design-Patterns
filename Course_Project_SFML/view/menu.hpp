#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu
{
private:
    sf::Font font;
    int selectedIndex;

public:
    std::vector<sf::Text> menuOptions;

    Menu(const std::vector<std::string> &options, float width, float height);
    void draw(sf::RenderWindow &window);
    int getOptionClicked(const sf::Vector2f &mousePos);
    void highlightOption(const sf::Vector2f &mousePos);
};

