#pragma once
#include "GridFactory.hpp"

class EasyGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
};

class MediumGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
};

class HardGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
};
