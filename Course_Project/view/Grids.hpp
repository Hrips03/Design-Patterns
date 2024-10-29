#pragma once
#include "IGrid.hpp"
#include <vector>

class EasyGrid : public IGrid {
public:
    EasyGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void revealCell(int row, int col) override;

private:
    std::vector<std::vector<std::string>> grid;
    // int generateCellValue(int row, int col);
};

// MediumGrid class
class MediumGrid : public IGrid {
public:
    MediumGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void revealCell(int row, int col) override;

private:
    std::vector<std::vector<std::string>> grid;
    // int generateCellValue(int row, int col);
};

// HardGrid class
class HardGrid : public IGrid {
public:
    HardGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void revealCell(int row, int col) override;

private:
    std::vector<std::vector<std::string>> grid;
    // int generateCellValue(int row, int col);
};