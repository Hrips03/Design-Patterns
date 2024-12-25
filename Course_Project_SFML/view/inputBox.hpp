#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

class InputBox
{
public:
    InputBox(float x, float y, float width, float height, const std::string &placeholder, bool isPassword = false);
    void handleInput(sf::Event &event);
    void draw(sf::RenderWindow &window);
    void setFocus(bool focus);
    std::string getInputText() const;
    sf::FloatRect getGlobalBounds() const;

private:
    std::string displayText; // To store text for display
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string inputText;
    std::string placeholder;
    bool isFocused;
    bool isPassword;
};

#endif // INPUTBOX_HPP
