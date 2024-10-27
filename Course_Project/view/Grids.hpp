#pragma once
#include "IGrid.hpp"

class EasyGrid : public IGrid {
public:
    void draw() override;
};

class MediumGrid : public IGrid {
public:
    void draw() override;
};

class HardGrid : public IGrid {
public:
    void draw() override;
};
