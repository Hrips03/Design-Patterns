#pragma once
#include <iostream>

class IGrid {
public:
    virtual void draw() = 0;
    virtual void markCell(int row, int col) = 0;
    virtual void unmarkCell(int row, int col) = 0;
    virtual bool revealCell(int row, int col) = 0;
    virtual void generateGrid() = 0;
    virtual bool checkWin() const = 0;
    virtual ~IGrid() = default;
};