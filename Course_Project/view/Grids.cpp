#include "Grids.hpp"

EasyGrid::EasyGrid() : m_emptyGrid(9, std::vector<std::string>(9, "[🟦]")), m_fullGrid(9, std::vector<std::string>(9, "")) {}

void EasyGrid::draw()
{
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;
        
        std::cout << std::endl;
    }
}


void EasyGrid::markCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🚩]";
}

void EasyGrid::unmarkCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🟦]";
}

MediumGrid::MediumGrid() : m_emptyGrid(16, std::vector<std::string>(16, "[🟦]")), m_fullGrid(16, std::vector<std::string>(16, "")) {}

void MediumGrid::draw()
{
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;
        
        std::cout << std::endl;
    }
}


void MediumGrid::markCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🚩]";
}

void MediumGrid::unmarkCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🟦]";
}

HardGrid::HardGrid() : m_emptyGrid(16, std::vector<std::string>(30, "[🟦]")), m_fullGrid(16, std::vector<std::string>(30, "")) {}

void HardGrid::draw()
{
    for (const auto &row : m_emptyGrid)
    {
        for (const auto &cell : row)
            std::cout << cell;
        
        std::cout << std::endl;
    }
}

void HardGrid::markCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🚩]";
}

void HardGrid::unmarkCell(int row, int col)
{
    m_emptyGrid[row][col] = "[🟦]";
}