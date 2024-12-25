#include "Grid.hpp"

Grid::Grid(int row, int col, int mines): m_row(row), m_col(col), m_mines(mines),m_emptyGrid(m_row, std::vector<std::string>(m_col, "[🟦]")), m_fullGrid(m_row, std::vector<std::string>(m_col, "")){}
 
void Grid::draw() 
{
    std::cout << "Mines: " << m_mines << std::endl;
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;

        std::cout << std::endl;
    }
}

void Grid::markCell(int row, int col)
{
    if (row <= 8 && col <= 8 && m_emptyGrid[row][col] == "[🟦]")
    {
        m_emptyGrid[row][col] = "[🚩]";
        m_mines--;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 8.\n";
    }
}

void Grid::unmarkCell(int row, int col)
{
    if (row <= 8 && col <= 8 && m_emptyGrid[row][col] == "[🚩]")
    {
        m_emptyGrid[row][col] = "[🟦]";
        m_mines++;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 8.\n";
    }
}
