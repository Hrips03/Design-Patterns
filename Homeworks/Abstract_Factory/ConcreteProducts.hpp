#pragma once
#include "AbstractProduct.hpp"
#include <iostream>

class SmartPhone : public ElectronicDevice
{
public:
    void starting() override;
};

class Tablet : public ElectronicDevice
{
public:
    void starting() override;
};

class Laptop : public ElectronicDevice
{
public:
    void starting() override;
};