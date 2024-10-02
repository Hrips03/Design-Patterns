#pragma once
#include "Vehicle.hpp"

struct VehicleFactory
{
    static Vehicle newCar(std::string name);
    static Vehicle newMotorcycle(std::string name);
};