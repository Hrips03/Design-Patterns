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
    text.setCharacterSize(15); // Set the text size to make it smaller
    text.setPosition(x + 5, y + 5);
    text.setString(placeholder);
}


void InputBox::handleInput(sf::Event &event)
{
    if (isFocused && event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == 8 && !inputText.empty())  // Backspace
        {
            inputText.pop_back();  // Remove last character from the input
        }
        else if (event.text.unicode >= 32 && event.text.unicode <= 126)  // Printable characters
        {
            inputText += static_cast<char>(event.text.unicode);  // Add character to input
        }

        //displayText = inputText;  // Update the display text to match the actual input
        text.setString(inputText);  // Update the displayed text
    }
}


void InputBox::draw(sf::RenderWindow &window)
{
    if (inputText.empty() && !isFocused)
    {
        text.setString(placeholder); // Show placeholder when no input and not focused
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
        box.setFillColor(sf::Color(200, 200, 255)); // Highlight input box on focus
    }
    else
    {
        box.setFillColor(sf::Color::White); // Default color
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
