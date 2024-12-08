#include "Grids.hpp"

EasyGrid::EasyGrid() : m_emptyGrid(9, std::vector<std::string>(9, "[🟦]")), m_fullGrid(9, std::vector<std::string>(9, "")) {}

void EasyGrid::draw()
{
    std::cout << "Mines: " << totalMines << std::endl;
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;

        std::cout << std::endl;
    }
}

void EasyGrid::markCell(int row, int col)
{
    if (row <= 8 && col <= 8 && m_emptyGrid[row][col] == "[🟦]")
    {
        m_emptyGrid[row][col] = "[🚩]";
        totalMines--;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 8.\n";
    }
}

void EasyGrid::unmarkCell(int row, int col)
{
    if (row <= 8 && col <= 8 && m_emptyGrid[row][col] == "[🚩]")
    {
        m_emptyGrid[row][col] = "[🟦]";
        totalMines++;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 8.\n";
    }
}

MediumGrid::MediumGrid() : m_emptyGrid(16, std::vector<std::string>(16, "[🟦]")), m_fullGrid(16, std::vector<std::string>(16, "")) {}

void MediumGrid::draw()
{
    std::cout << "Mines: " << totalMines << std::endl;
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;

        std::cout << std::endl;
    }
}

void MediumGrid::markCell(int row, int col)
{
    if (row <= 15 && col <= 15 && m_emptyGrid[row][col] == "[🟦]")
    {
        m_emptyGrid[row][col] = "[🚩]";
        totalMines--;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 15.\n";
    }
}

void MediumGrid::unmarkCell(int row, int col)
{
    if (row <= 15 && col <= 15 && m_emptyGrid[row][col] == "[🚩]")
    {
        m_emptyGrid[row][col] = "[🟦]";
        totalMines++;
    }
    else{
        std::cout << "Input numbers should be less than or equal to 15.\n";
    }
}

HardGrid::HardGrid() : m_emptyGrid(16, std::vector<std::string>(30, "[🟦]")), m_fullGrid(16, std::vector<std::string>(30, "")) {}

void HardGrid::draw()
{
    std::cout << "Mines: " << totalMines << std::endl;
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;

        std::cout << std::endl;
    }
}

void HardGrid::markCell(int row, int col)
{
    if (row <= 15 && col <= 39 && m_emptyGrid[row][col] == "[🟦]")
    {
        m_emptyGrid[row][col] = "[🚩]";
        totalMines--;
    }
    else{
        std::cout << "Input numbers should be less than or equal to rows: 15, cols: 39.\n";
    }
}

void HardGrid::unmarkCell(int row, int col)
{
    if (row <= 15 && col <= 39 && m_emptyGrid[row][col] == "[🚩]")
    {
        m_emptyGrid[row][col] = "[🟦]";
        totalMines++;
    }
    else{
        std::cout << "Input numbers should be less than or equal to rows: 15, cols: 39.\n";
    }
}