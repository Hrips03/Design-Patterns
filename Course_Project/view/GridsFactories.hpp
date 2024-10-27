#pragma once
#include "GridFactory.hpp"

class EasyGridFactory : public GridFactory
{
public:
    IGrid* createGrid() override;
};

class MediumGridFactory : public GridFactory
{
public:
    IGrid* createGrid() override;
};

class HardGridFactory : public GridFactory
{
public:
    IGrid* createGrid() override;
};
