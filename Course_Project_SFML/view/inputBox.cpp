#include "inputBox.hpp"
#include <iostream>

InputBox::InputBox(float x, float y, float width, float height, const std::string &placeholder, bool isPassword)
    : isFocused(false), inputText(""), placeholder(placeholder), isPassword(isPassword)
{
    box.setPosition(x, y);
    box.setSize(sf::Vector2f(width, height));
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        exit(1);
    }

    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(15); 
    text.setPosition(x + 5, y + 5);
    text.setString(placeholder);
}


void InputBox::handleInput(sf::Event &event)
{
    if (isFocused && event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == 8 && !inputText.empty())  
        {
            inputText.pop_back(); 
        }
        else if (event.text.unicode >= 32 && event.text.unicode <= 126) 
        {
            inputText += static_cast<char>(event.text.unicode);  
        }
        text.setString(inputText); 
    }
}


void InputBox::draw(sf::RenderWindow &window)
{
    if (inputText.empty() && !isFocused)
    {
        text.setString(placeholder); 
    }
    else
    {
        text.setString(inputText);
    }
    window.draw(box);
    window.draw(text);
}

void InputBox::setFocus(bool focus)
{
    isFocused = focus;
    if (isFocused)
    {
        box.setFillColor(sf::Color(200, 200, 255)); 
    }
    else
    {
        box.setFillColor(sf::Color::White); 
    }
}

std::string InputBox::getInputText() const
{
    return inputText;
}

sf::FloatRect InputBox::getGlobalBounds() const
{
    return box.getGlobalBounds();
}
