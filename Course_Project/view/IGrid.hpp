#pragma once
#include <iostream>

class IGrid
{
public:
    virtual void draw() = 0;
    virtual ~IGrid() = default;
};