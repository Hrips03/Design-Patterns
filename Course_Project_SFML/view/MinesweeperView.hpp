#pragma once
#include <SFML/Graphics.hpp>
#include "../model/MinesweeperModel.hpp"
#include <iostream>
#include <memory>

class MinesweeperView
{
private:
    sf::Font font;  
public:
    sf::RectangleShape restartButton;
    sf::Text restartText;
    sf::RenderWindow window;
    MinesweeperView(int width, int height);
    void display(MinesweeperModel &model, sf::Time &elapsed);
    void displayTimer(sf::Time &elapsed);
    void displayMinesRemaining(int minesRemaining);
    void displayMessage(const std::string &message);
    void handleMouseClick(sf::Mouse::Button button, int x, int y, MinesweeperModel &model);
    void resetButton();
};


