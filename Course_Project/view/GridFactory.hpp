#pragma once
#include <memory>
#include "IGrid.hpp"

class GridFactory {
public:
    virtual IGrid* createGrid() = 0;
    virtual ~GridFactory() = default;
};
