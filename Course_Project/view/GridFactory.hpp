#pragma once
#include <memory>
#include "IGrid.hpp"

class GridFactory {
public:
    virtual IGrid* createEmptyGrid() = 0;
    //virtual IGrid* generateGrid() = 0;
    virtual ~GridFactory() = default;
};
