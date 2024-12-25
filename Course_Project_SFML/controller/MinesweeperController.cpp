#include "../controller/MinesweeperController.hpp"

MinesweeperController::MinesweeperController(int rows, int cols, int mines, std::vector<std::string> userInfo)
    : model(rows, cols, mines), view(cols * 40, rows * 40 + 40), m_userInfo(userInfo)
{
}

void MinesweeperController::run()
{
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero; // Accumulated time for the current game
    sf::Time finalTime = sf::Time::Zero;   // Freezed time to display after game ends

    while (view.window.isOpen())
    {
        sf::Event event;
        while (view.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                view.window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (view.restartButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    model.resetGame();
                    elapsedTime = sf::Time::Zero; // Reset timer for a new game
                    clock.restart();              // Restart the clock
                }
                else if (!model.gameOver && !model.gameWon)
                {
                    view.handleMouseClick(event.mouseButton.button,
                                          event.mouseButton.x,
                                          event.mouseButton.y,
                                          model);
                }
            }
        }

        // Update timer only if the game is ongoing
        if (!model.gameOver && !model.gameWon)
        {
            elapsedTime = clock.getElapsedTime();
        }
        else
        {
            finalTime = elapsedTime; // Freeze the timer when the game ends
        }

        // Display game status message if necessary
        if (model.gameOver)
        {
            view.displayMessage("Game Over");
        }
        else if (model.gameWon)
        {
            view.displayMessage("You Win!");
            SQLiteDB *db = SQLiteDB::getInstance();
            if (m_userInfo[0] != "")
            {
                std::cout << "updateing";
                int totalSeconds = static_cast<int>(elapsedTime.asSeconds());

                // Convert seconds to minutes and remaining seconds
                int minutes = totalSeconds / 60;
                int seconds = totalSeconds % 60;

                // Create the formatted string with leading zeros if necessary
                std::string timeString =
                    (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
                    (seconds < 10 ? "0" : "") + std::to_string(seconds);
                
                m_userInfo[2] = timeString;
                db->updateBestScore(m_userInfo[0], m_userInfo[1], m_userInfo[2]);
            }
        }

        // Display using finalTime after game ends, or elapsedTime otherwise
        view.display(model, model.gameOver || model.gameWon ? finalTime : elapsedTime);
    }
}
