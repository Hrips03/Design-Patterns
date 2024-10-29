#include "Grids.hpp"

EasyGrid::EasyGrid() : grid(9, std::vector<std::string>(9, "[  ]")) {}  

void EasyGrid::draw() {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

void EasyGrid::markCell(int row, int col) {
    grid[row][col] = "[🚩]";  
}

void EasyGrid::revealCell(int row, int col) {
    //grid[row][col] = generateCellValue(row, col); 
    grid[row][col] =  "[🆒]";
}




MediumGrid::MediumGrid() : grid(16, std::vector<std::string>(16, "[  ]")) {} 

void MediumGrid::draw() {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

void MediumGrid::markCell(int row, int col) {
    grid[row][col] = "[🚩]";
}

void MediumGrid::revealCell(int row, int col) {
    //grid[row][col] = generateCellValue(row, col);
    grid[row][col] =  "[🆒]";
}




HardGrid::HardGrid() : grid(16, std::vector<std::string>(30, "[  ]")) {}  

void HardGrid::draw() {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

void HardGrid::markCell(int row, int col) {
    grid[row][col] = "[🚩]";
}

void HardGrid::revealCell(int row, int col) {
    //grid[row][col] = generateCellValue(row, col);
    grid[row][col] =  "[🆒]";

}