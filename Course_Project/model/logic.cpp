// #include "logic.hpp"

// void EasyGrid::generateGrid()
// {
//     srand(static_cast<unsigned int>(time(0)));

//     for (int i = 0; i < 10; i++)
//     {
//         int randomNumRow = rand() % 9;
//         int randomNumCol = rand() % 9;
//         if (m_fullGrid[randomNumRow][randomNumCol] == "[💣]")
//             i--;
//         else
//             m_fullGrid[randomNumRow][randomNumCol] = "[💣]";
//     }

//     for (int i = 0; i < 9; i++)
//         for (int j = 0; j < 9; j++)
//             if (m_fullGrid[i][j] != "[💣]")
//             {
//                 int count = 0;
//                 for (int di = -1; di <= 1; di++)

//                     for (int dj = -1; dj <= 1; dj++)
//                     {
//                         if (di == 0 && dj == 0)
//                             continue;

//                         int ni = i + di;
//                         int nj = j + dj;

//                         if (ni >= 0 && ni < 9 && nj >= 0 && nj < 9 && m_fullGrid[ni][nj] == "[💣]")
//                             count++;
//                     }

//                 if (count == 0)
//                     m_fullGrid[i][j] = "[🔲]";
//                 else
//                     m_fullGrid[i][j] = "[" + std::to_string(count) + " ]";
//             }

//     // for (const auto &row : m_fullGrid)
//     // {
//     //     for (const auto &cell : row)
//     //     {
//     //         std::cout << cell;
//     //     }
//     //     std::cout << std::endl;
//     // }
//     // std::cout << std::endl;
// }

// bool EasyGrid::revealCell(int row, int col)
// {
   
//     if (row < 0 || row >= 9 || col < 0 || col >= 9)
//         return false;
    
//     if (m_emptyGrid[row][col] == m_fullGrid[row][col])
//         return false;
    

//     m_emptyGrid[row][col] = m_fullGrid[row][col];


//     if (m_fullGrid[row][col] == "[💣]")
//     {
//         std::cout << "Game Over! You hit a bomb!" << std::endl;
//         return true;
//     }


//     revealedCells++;

//     if (m_fullGrid[row][col] == "[🔲]")
//     {
//         for (int di = -1; di <= 1; di++)
//         {
//             for (int dj = -1; dj <= 1; dj++)
//             {
//                 if (di == 0 && dj == 0)
//                     continue;

//                 revealCell(row + di, col + dj);
//             }
//         }
//     }
//     return false;
// }


// bool EasyGrid::checkWin() const
// {
//     return (revealedCells == (totalCells - totalMines) || revealedCells == (totalCells - totalMines + 1));
// }

// void MediumGrid::generateGrid()
// {
//     srand(static_cast<unsigned int>(time(0)));

//     for (int i = 0; i < 40; i++)
//     {
//         int randomNumRow = rand() % 16;
//         int randomNumCol = rand() % 16;
//         if (m_fullGrid[randomNumRow][randomNumCol] == "[💣]")
//             i--;
//         m_fullGrid[randomNumRow][randomNumCol] = "[💣]";
//     }

//     for (int i = 0; i < 16; i++)
//         for (int j = 0; j < 16; j++)
//         {
//             if (m_fullGrid[i][j] != "[💣]")
//             {
//                 int count = 0;

//                 for (int di = -1; di <= 1; di++)
//                     for (int dj = -1; dj <= 1; dj++)
//                     {
//                         if (di == 0 && dj == 0)
//                             continue;

//                         int ni = i + di;
//                         int nj = j + dj;

//                         if (ni >= 0 && ni < 16 && nj >= 0 && nj < 16 && m_fullGrid[ni][nj] == "[💣]")
//                             count++;
//                     }
//                 if (count == 0)
//                     m_fullGrid[i][j] = "[🔲]";
//                 else
//                     m_fullGrid[i][j] = "[" + std::to_string(count) + " ]";
//             }
//         }

//     // for (const auto &row : m_fullGrid)
//     // {
//     //     for (const auto &cell : row)
//     //     {
//     //         std::cout << cell;
//     //     }
//     //     std::cout << std::endl;
//     // }
//     // std::cout << std::endl;
// }

// bool MediumGrid::revealCell(int row, int col)
// {
//     if (row < 0 || row >= 16 || col < 0 || col >= 16 || m_emptyGrid[row][col] == m_fullGrid[row][col])
//     {
//         std::cout << "Input numbers should be less than or equal to 15.\n";
//         return false;
//     }

//     m_emptyGrid[row][col] = m_fullGrid[row][col];

//     if (m_fullGrid[row][col] == "[💣]")
//     {
//         std::cout << "Game Over! You hit a bomb!" << std::endl;
//         return true;
//     }

//     revealedCells++;

//     if (m_fullGrid[row][col] == "[🔲]")
//         for (int di = -1; di <= 1; di++)
//             for (int dj = -1; dj <= 1; dj++)
//                 if ((di != 0 || dj != 0) && row + di >= 0 && row + di < 9 && col + dj >= 0 && col + dj < 9)
//                 {
//                     revealedCells++;
//                     revealCell(row + di, col + dj);
//                 }

//     return false;
// }

// bool MediumGrid::checkWin() const
// {
//     return (revealedCells == (totalCells - totalMines) || revealedCells == (totalCells - totalMines + 1));
// }

// void HardGrid::generateGrid()
// {
//     srand(static_cast<unsigned int>(time(0)));

//     for (int i = 0; i < 99; i++)
//     {
//         int randomNumRow = rand() % 16;
//         int randomNumCol = rand() % 30;
//         if (m_fullGrid[randomNumRow][randomNumCol] == "[💣]")
//             i--;
//         m_fullGrid[randomNumRow][randomNumCol] = "[💣]";
//     }

//     for (int i = 0; i < 16; i++)
//         for (int j = 0; j < 30; j++)
//         {
//             if (m_fullGrid[i][j] != "[💣]")
//             {
//                 int count = 0;

//                 for (int di = -1; di <= 1; di++)
//                     for (int dj = -1; dj <= 1; dj++)
//                     {
//                         if (di == 0 && dj == 0)
//                             continue;

//                         int ni = i + di;
//                         int nj = j + dj;

//                         if (ni >= 0 && ni < 16 && nj >= 0 && nj < 30 && m_fullGrid[ni][nj] == "[💣]")
//                             count++;
//                     }

//                 if (count == 0)
//                     m_fullGrid[i][j] = "[🔲]";
//                 else
//                     m_fullGrid[i][j] = "[" + std::to_string(count) + " ]";
//             }
//         }

//     // for (const auto &row : m_fullGrid)
//     // {
//     //     for (const auto &cell : row)
//     //     {
//     //         std::cout << cell;
//     //     }
//     //     std::cout << std::endl;
//     // }
//     // std::cout << std::endl;
// }

// bool HardGrid::revealCell(int row, int col)
// {
//     if (row < 0 || row >= 16 || col < 0 || col >= 30 || m_emptyGrid[row][col] == m_fullGrid[row][col])
//     {
//         std::cout << "Input numbers should be less than or equal to rows: 15, cols: 39.\n";
//         return false;
//     }

//     m_emptyGrid[row][col] = m_fullGrid[row][col];
//     if (m_fullGrid[row][col] == "[💣]")
//     {
//         std::cout << "Game Over! You hit a bomb!" << std::endl;
//         return true;
//     }
//     revealedCells++;

//     if (m_fullGrid[row][col] == "[🔲]")
//         for (int di = -1; di <= 1; di++)
//             for (int dj = -1; dj <= 1; dj++)
//                 if ((di != 0 || dj != 0) && row + di >= 0 && row + di < 9 && col + dj >= 0 && col + dj < 9)
//                 {
//                     revealedCells++;
//                     revealCell(row + di, col + dj);
//                 }

//     return false;
// }

// bool HardGrid::checkWin() const
// {
//     return (revealedCells == (totalCells - totalMines) || revealedCells == (totalCells - totalMines + 1));
// }
