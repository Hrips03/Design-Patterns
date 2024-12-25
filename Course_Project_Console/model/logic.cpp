#include "logic.hpp"

void Grid::generateGrid()
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < m_mines; i++)
    {
        int randomNumRow = rand() % m_row;
        int randomNumCol = rand() % m_col;
        if (m_fullGrid[randomNumRow][randomNumCol] == "[💣]")
            i--;
        else
            m_fullGrid[randomNumRow][randomNumCol] = "[💣]";
    }

    for (int i = 0; i < m_row; i++)
        for (int j = 0; j < m_col; j++)
            if (m_fullGrid[i][j] != "[💣]")
            {
                int count = 0;
                for (int di = -1; di <= 1; di++)

                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (di == 0 && dj == 0)
                            continue;

                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < m_row && nj >= 0 && nj < m_col && m_fullGrid[ni][nj] == "[💣]")
                            count++;
                    }

                if (count == 0)
                    m_fullGrid[i][j] = "[🔲]";
                else
                    m_fullGrid[i][j] = "[" + std::to_string(count) + " ]";
            }

    // for (const auto &row : m_fullGrid)
    // {
    //     for (const auto &cell : row)
    //     {
    //         std::cout << cell;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}

bool Grid::revealCell(int row, int col)
{

    if (row < 0 || row >= m_row || col < 0 || col >= m_col)
        return false;

    if (m_emptyGrid[row][col] == m_fullGrid[row][col])
        return false;

    m_emptyGrid[row][col] = m_fullGrid[row][col];

    if (m_fullGrid[row][col] == "[💣]")
    {
        std::cout << "Game Over! You hit a bomb!" << std::endl;
        return true;
    }

    m_revealedCells++;

    if (m_fullGrid[row][col] == "[🔲]")
    {
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di == 0 && dj == 0)
                    continue;

                revealCell(row + di, col + dj);
            }
        }
    }
    return false;
}

bool Grid::checkWin() const
{
    int totalCells = m_col * m_row;
    return (m_revealedCells == (totalCells - m_mines) || m_revealedCells == (totalCells - m_mines + 1));
}

