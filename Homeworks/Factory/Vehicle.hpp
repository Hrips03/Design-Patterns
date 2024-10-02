#pragma once
#include <iostream>

struct Vehicle
{
    std::string name;
    friend class VehicleFactory;

private:
    Vehicle(std::string nameOfVehicle) : name{nameOfVehicle} {}
};