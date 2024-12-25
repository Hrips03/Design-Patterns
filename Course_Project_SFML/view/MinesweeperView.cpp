#include "MinesweeperView.hpp"

MinesweeperView::MinesweeperView(int width, int height)
{
    window.create(sf::VideoMode(width, height), "Minesweeper");
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    sf::Vector2u windowSize = window.getSize();

    int posX = (desktopMode.width - windowSize.x) / 2;
    int posY = (desktopMode.height - windowSize.y) / 2;

    window.setPosition(sf::Vector2i(posX, posY));

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error loading font\n";
        exit(1);
    }

    sf::Texture restartTexture;
    if (!restartTexture.loadFromFile("smile_face.jpg"))  // Default texture (not clicked)
    {
        std::cerr << "Failed to load restart button texture!" << std::endl;
    }

    restartButton.setSize(sf::Vector2f(38.f, 38.f));
    restartButton.setPosition(160.f, 0.f);
    restartButton.setTexture(&restartTexture);
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

    sf::Vector2u windowSize = window.getSize();
    float restartButtonX = (windowSize.x - restartButton.getSize().x) / 2;
    restartButton.setPosition(restartButtonX, 0.f);

    

    sf::Texture restartTexture;
    if (!restartTexture.loadFromFile("smile_face.jpg"))  // Default texture (not clicked)
    {
        std::cerr << "Failed to load restart button texture!" << std::endl;
    }

    // Load texture for the game over button (or won button)
    sf::Texture gameOverTexture;
    if (!gameOverTexture.loadFromFile("sad_face.jpg"))  // Texture for game over or won state
    {
        std::cerr << "Failed to load game over texture!" << std::endl;
    }

    // Set the appropriate texture based on the game state
    if (model.gameOver || model.gameWon)
    {
        restartButton.setTexture(&gameOverTexture);  // Change texture when game over or won
    }
    else
    {
        restartButton.setTexture(&restartTexture);  // Default texture for active button
    }

    window.draw(restartButton);

    displayMinesRemaining(model.minesRemaining);
    displayTimer(elapsed);

    sf::Texture flagTexture;
    if (!flagTexture.loadFromFile("flag.jpg"))
    {
        std::cerr << "Failed to load cell image!" << std::endl;
    }

    sf::Texture mineTexture;
    if (!mineTexture.loadFromFile("mine.jpg"))
    {
        std::cerr << "Failed to load cell image!" << std::endl;
    }


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
                    cell.setTexture(&mineTexture);
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
                cell.setTexture(&flagTexture);
            }
            else
            {
                cell.setFillColor(sf::Color(50, 50, 150));
            }

            window.draw(cell);

            for (int i = 0; i < model.rows; ++i)
            {
                for (int j = 0; j < model.cols; ++j)
                {
                    sf::RectangleShape cell(sf::Vector2f(40 - 2, 40 - 2)); 
                    cell.setPosition(j * 40, i * 40 + 40);                 

                    if (model.revealed[i][j])
                    {
                        if (model.grid[i][j] == 9)
                        {
                            cell.setFillColor(sf::Color::Black); 
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
                                number.setPosition(j * 40 + 40 / 2, i * 40 + 40 + 40 / 2); 

                                window.draw(number); 
                            }
                        }
                    }
                    else if (model.flagged[i][j])
                    {
                        cell.setFillColor(sf::Color::Red); 
                    }
                    else
                    {
                        cell.setFillColor(sf::Color(100, 100, 100)); 
                    }
                   
                }
            }
        }
    }

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
 
    int minutes = seconds / 60;
    seconds = seconds % 60;

    sf::Text timerText;
    timerText.setFont(font);
    timerText.setString("Time: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
    timerText.setCharacterSize(20);
    timerText.setFillColor(sf::Color::Black);
    sf::Vector2u windowSize = window.getSize();
    timerText.setPosition(windowSize.x - timerText.getLocalBounds().width - 10.f, 10.f);

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
        return; 
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
    // Load the texture
    sf::Texture buttonTexture;
    if (!buttonTexture.loadFromFile("smile_face.jpg"))  // Replace with the path to your texture
    {
        std::cerr << "Failed to load button texture!" << std::endl;
        return;  // Early return if texture fails to load
    }

    // Set the texture for the restart button
    restartButton.setTexture(&buttonTexture);

    // Optional: Ensure the button's size matches the texture size
    restartButton.setSize(sf::Vector2f(buttonTexture.getSize().x, buttonTexture.getSize().y));
}
