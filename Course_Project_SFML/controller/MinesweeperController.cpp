#include "../controller/MinesweeperController.hpp"

MinesweeperController::MinesweeperController(int rows, int cols, int mines)
    : model(rows, cols, mines), view(cols * 40, rows * 40 + 40) {}


void MinesweeperController::run()
{
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;   // Accumulated time for the current game
    sf::Time finalTime = sf::Time::Zero;    // Freezed time to display after game ends

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
                    elapsedTime = sf::Time::Zero;  // Reset timer for a new game
                    clock.restart();               // Restart the clock
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
            finalTime = elapsedTime;  // Freeze the timer when the game ends
        }

        // Display game status message if necessary
        if (model.gameOver)
        {
            view.displayMessage("Game Over");
        }
        else if (model.gameWon)
        {
            view.displayMessage("You Win!");
        }

        // Display using finalTime after game ends, or elapsedTime otherwise
        view.display(model, model.gameOver || model.gameWon ? finalTime : elapsedTime);
    }
}
