#pragma once
#include "IGrid.hpp"
#include <vector>

class EasyGrid : public IGrid
{
public:
    EasyGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void unmarkCell(int row, int col) override;
    bool revealCell(int row, int col) override;
    void generateGrid() override;
    bool checkWin() const override;
private:
    const int totalCells = 81;
    int totalMines = 10;
    int revealedCells = 0;
    std::vector<std::vector<std::string>> m_emptyGrid;
    std::vector<std::vector<std::string>> m_fullGrid;
};


class MediumGrid : public IGrid
{
public:
    MediumGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void unmarkCell(int row, int col) override;
    bool revealCell(int row, int col) override;
    void generateGrid() override;
    bool checkWin() const override;
private:
    const int totalCells = 256;
    int totalMines = 40;
    int revealedCells = 0;
    std::vector<std::vector<std::string>> m_emptyGrid;
    std::vector<std::vector<std::string>> m_fullGrid;
};


class HardGrid : public IGrid
{
public:
    HardGrid();
    void draw() override;
    void markCell(int row, int col) override;
    void unmarkCell(int row, int col) override;
    bool revealCell(int row, int col) override;
    void generateGrid() override;
    bool checkWin() const override;
private:
    const int totalCells = 480;
    int totalMines = 99;
    int revealedCells = 0;
    std::vector<std::vector<std::string>> m_emptyGrid;
    std::vector<std::vector<std::string>> m_fullGrid;
};
