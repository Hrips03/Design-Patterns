#include "VehicleFactory.hpp"

Vehicle VehicleFactory::newCar(std::string name)
{
    return Vehicle{name};
}

Vehicle VehicleFactory::newMotorcycle(std::string name)
{
    return Vehicle{name};
}
