#include "MinesweeperView.hpp"

MinesweeperView::MinesweeperView(int width, int height)
{
    window.create(sf::VideoMode(width, height), "Minesweeper");

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error loading font\n";
        exit(1);
    }

    restartButton.setSize(sf::Vector2f(38.f, 38.f));
    restartButton.setPosition(160.f, 0.f);
    restartButton.setFillColor(sf::Color::Green);

    restartText.setFont(font);
    restartText.setString("R");
    restartText.setCharacterSize(20);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(170.f, 1.f);
}

sf::Color getNumberColor(int number)
{
    switch (number)
    {
    case 1:
        return sf::Color::Blue;
    case 2:
        return sf::Color::Green;
    case 3:
        return sf::Color::Red;
    case 4:
        return sf::Color::Cyan;
    case 5:
        return sf::Color::Magenta;
    case 6:
        return sf::Color::Yellow;
    case 7:
        return sf::Color::Black;
    case 8:
        return sf::Color::White;
    default:
        return sf::Color::Black;
    }
}

void MinesweeperView::displayMessage(const std::string &message)
{
    sf::Text messageText;
    messageText.setFont(font);
    messageText.setString(message);
    messageText.setCharacterSize(20);
    messageText.setFillColor(sf::Color::Red);
    messageText.setPosition(window.getSize().x / 2 - messageText.getLocalBounds().width / 2,
                            window.getSize().y / 2 - messageText.getLocalBounds().height / 2);
    window.draw(messageText);
}

void MinesweeperView::display(MinesweeperModel &model, sf::Time &elapsed)
{
    window.clear(sf::Color::White);

    if (model.gameOver || model.gameWon)
    {
        restartButton.setFillColor(sf::Color::Red);  // Change to red when game ends
    }
    else
    {
        restartButton.setFillColor(sf::Color::Green);  // Default color
    }

    window.draw(restartButton);
    window.draw(restartText);

    displayMinesRemaining(model.minesRemaining);
    displayTimer(elapsed);

    // Draw the grid
    for (int i = 0; i < model.rows; ++i)
    {
        for (int j = 0; j < model.cols; ++j)
        {
            sf::RectangleShape cell(sf::Vector2f(40.f - 2, 40.f - 2));
            cell.setPosition(j * 40, i * 40 + 40);

            if (model.revealed[i][j])
            {
                if (model.grid[i][j] == 9)
                {
                    cell.setFillColor(sf::Color::Black); // Mine
                }
                else
                {
                    cell.setFillColor(sf::Color(200, 200, 200));

                    if (model.grid[i][j] > 0)
                    {
                        sf::Text number;
                        number.setFont(font);
                        number.setString(std::to_string(model.grid[i][j]));
                        number.setCharacterSize(24);
                        number.setFillColor(getNumberColor(model.grid[i][j]));

                        sf::FloatRect textBounds = number.getLocalBounds();
                        number.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                         textBounds.top + textBounds.height / 2.0f);
                        number.setPosition(j * 40 + 20, i * 40 + 60);
                        window.draw(number);
                    }
                }
            }
            else if (model.flagged[i][j])
            {
                cell.setFillColor(sf::Color::Red); // Flagged cell
            }
            else
            {
                cell.setFillColor(sf::Color(100, 100, 100));
            }

            window.draw(cell);

            for (int i = 0; i < model.rows; ++i)
            {
                for (int j = 0; j < model.cols; ++j)
                {
                    sf::RectangleShape cell(sf::Vector2f(40 - 2, 40 - 2)); // Cell shape
                    cell.setPosition(j * 40, i * 40 + 40);                 // Adjust position for the grid below the remaining mines display

                    if (model.revealed[i][j])
                    {
                        if (model.grid[i][j] == 9)
                        {
                            cell.setFillColor(sf::Color::Black); // Mine
                        }
                        else
                        {
                            cell.setFillColor(sf::Color(200, 200, 200)); // Revealed cell

                            // Draw number if it's > 0
                            if (model.grid[i][j] > 0)
                            {
                                sf::Text number;
                                number.setFont(font);
                                number.setString(std::to_string(model.grid[i][j]));
                                number.setCharacterSize(24); // Set text size
                                number.setFillColor(getNumberColor(model.grid[i][j]));

                                // Position the number in the center of the cell
                                sf::FloatRect textBounds = number.getLocalBounds();
                                number.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                                 textBounds.top + textBounds.height / 2.0f);
                                number.setPosition(j * 40 + 40 / 2, i * 40 + 40 + 40 / 2); // Center number in cell

                                window.draw(number); // Draw the number
                            }
                        }
                    }
                    else if (model.flagged[i][j])
                    {
                        cell.setFillColor(sf::Color::Red); // Flagged
                    }
                    else
                    {
                        cell.setFillColor(sf::Color(100, 100, 100)); // Hidden
                    }

                    // window.draw(cell); // Draw the cell
                }
            }
        }
    }

    // Show Game Over or You Win message
    if (model.gameOver)
    {
        displayMessage("Game Over");
    }
    else if (model.gameWon)
    {
        displayMessage("You Win!");
    }

    window.display();
}

void MinesweeperView::displayTimer(sf::Time &elapsed)
{
    int seconds = static_cast<int>(elapsed.asSeconds());

    // Convert seconds to minutes and remaining seconds
    int minutes = seconds / 60;
    seconds = seconds % 60;

    // Create the timer text
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setString("Time: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
    timerText.setCharacterSize(20);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(255.f, 10.f);

    // Draw the timer on the window
    window.draw(timerText);
}

void MinesweeperView::displayMinesRemaining(int minesRemaining)
{
    sf::Text minesText;
    minesText.setFont(font);
    minesText.setString("Mines: " + std::to_string(minesRemaining));
    minesText.setCharacterSize(20);
    minesText.setFillColor(sf::Color::Black);
    minesText.setPosition(1.f, 10.f);
    window.draw(minesText);
}

void MinesweeperView::handleMouseClick(sf::Mouse::Button button, int x, int y, MinesweeperModel &model)
{
    if (model.gameOver || model.gameWon)
    {
        if (restartButton.getGlobalBounds().contains(x, y))
        {
            model.resetGame();
        }
        return;  // Prevent any further clicks when game is over
    }
    
    int row = (y - 40) / 40;
    int col = x / 40;

    if (button == sf::Mouse::Left)
    {
        if (model.isValidCell(row, col))
        {
            model.revealCell(row, col);
        }
    }
    else if (button == sf::Mouse::Right)
    {
        model.toggleFlag(row, col);
    }
}

void MinesweeperView::resetButton()
{
    restartButton.setFillColor(sf::Color::Green);
}

// void MinesweeperView::displayMessage(const std::string &message)
// {
//     sf::Text messageText;
//     messageText.setFont(font);
//     messageText.setString(message);
//     messageText.setCharacterSize(20);
//     messageText.setFillColor(sf::Color::Red);
//     messageText.setPosition(window.getSize().x / 2 - messageText.getLocalBounds().width / 2,
//                             window.getSize().y / 2 - messageText.getLocalBounds().height / 2);
//     window.draw(messageText);
// }
