#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>

class MinesweeperModel
{
public:
    int rows;
    int cols;
    int totalMines;
    int minesRemaining;
    bool gameOver;
    bool gameWon;

    std::vector<std::vector<int>> grid;      // 0: empty, 9: mine
    std::vector<std::vector<bool>> revealed; // true if the cell is revealed
    std::vector<std::vector<bool>> flagged;  // true if the cell is flagged

    MinesweeperModel(int rows, int cols, int mines);
    void placeMines();
    void calculateNumbers();
    void revealCell(int row, int col);
    void toggleFlag(int row, int col);
    void checkGameOver();
    bool isValidCell(int r, int c);
    void resetGame();
    void revealAllMines();
};