#pragma once
#include <iostream>

class IGrid {
public:
    virtual void draw() = 0;
    virtual void markCell(int row, int col) = 0;
    virtual void revealCell(int row, int col) = 0;
    virtual ~IGrid() = default;
};