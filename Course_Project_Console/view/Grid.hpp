#pragma once
#include <vector>
#include <iostream>

class Grid
{
    int m_row = 0;
    int m_col = 0;
    int m_mines = 0;
    int m_revealedCells = 0;

    std::vector<std::vector<std::string>> m_fullGrid;
    std::vector<std::vector<std::string>> m_emptyGrid;

public:
    Grid(int row, int col, int mines);
    void generateGrid();
    bool revealCell(int row, int col);
    void markCell(int row, int col);
    void unmarkCell(int row, int col);
    bool checkWin() const;
    void draw();
};