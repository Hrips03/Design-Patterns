#include "MinesweeperModel.hpp"

MinesweeperModel::MinesweeperModel(int rows, int cols, int mines)
    : rows(rows), cols(cols), totalMines(mines), gameOver(false), gameWon(false), minesRemaining(mines),
      grid(rows, std::vector<int>(cols, 0)),
      revealed(rows, std::vector<bool>(cols, false)),
      flagged(rows, std::vector<bool>(cols, false))
{
    srand(static_cast<unsigned>(time(nullptr)));
    placeMines();
    calculateNumbers();
}

void MinesweeperModel::placeMines()
{
    int placedMines = 0;
    while (placedMines < totalMines)
    {
        int r = rand() % rows;
        int c = rand() % cols;

        if (grid[r][c] != 9)
        {
            grid[r][c] = 9;
            ++placedMines;
        }
    }
}

void MinesweeperModel::calculateNumbers()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 9)
                continue;

            int mineCount = 0;
            for (int dr = -1; dr <= 1; ++dr)
            {
                for (int dc = -1; dc <= 1; ++dc)
                {
                    int nr = i + dr;
                    int nc = j + dc;
                    if (isValidCell(nr, nc) && grid[nr][nc] == 9)
                    {
                        ++mineCount;
                    }
                }
            }
            grid[i][j] = mineCount;
        }
    }
}
void MinesweeperModel::checkGameOver()
{
    bool allRevealed = true;
    bool allMinesFlagged = true;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 9)
            {
                if (!flagged[i][j])  
                    allMinesFlagged = false;
            }
            else
            {
                if (!revealed[i][j])
                    allRevealed = false;
            }
        }
    }

    if (allRevealed && allMinesFlagged)
    {
        gameWon = true;
    }


    if (gameOver || gameWon)
    {
        revealAllMines(); 
    }
}

void MinesweeperModel::revealCell(int row, int col)
{
    if (revealed[row][col] || flagged[row][col])
        return;

    revealed[row][col] = true;

    if (grid[row][col] == 9)  
    {
        gameOver = true;
    }
    else if (grid[row][col] == 0)  
    {
        for (int dr = -1; dr <= 1; ++dr)
        {
            for (int dc = -1; dc <= 1; ++dc)
            {
                int nr = row + dr;
                int nc = col + dc;
                if (isValidCell(nr, nc) && !revealed[nr][nc])
                {
                    revealCell(nr, nc);
                }
            }
        }
    }

    checkGameOver();  
}

void MinesweeperModel::toggleFlag(int row, int col)
{
    if (revealed[row][col])
        return;

    flagged[row][col] = !flagged[row][col];
    if (flagged[row][col])
        --minesRemaining;
    else
        ++minesRemaining;

    checkGameOver();  
}


bool MinesweeperModel::isValidCell(int r, int c)
{
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

void MinesweeperModel::resetGame()
{
    gameOver = false;
    gameWon = false;
    minesRemaining = totalMines;

    grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
    revealed = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
    flagged = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));

    placeMines();
    calculateNumbers();
}


void MinesweeperModel::revealAllMines()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 9)
            {
                revealed[i][j] = true;
            }
        }
    }
}
