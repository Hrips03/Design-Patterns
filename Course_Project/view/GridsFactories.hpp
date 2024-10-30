#pragma once
#include "GridFactory.hpp"

class EasyGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
    //IGrid* generateGrid() override;
};

class MediumGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
    // IGrid* generateGrid() override;

};

class HardGridFactory : public GridFactory
{
public:
    IGrid* createEmptyGrid() override;
    // IGrid* generateGrid() override;

};
