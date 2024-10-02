#include "VehicleFactory.hpp"

int main() {
    Vehicle car = VehicleFactory::newCar("Audi");
    std::cout << "Created vehicle: " << car.name << std::endl; 

    Vehicle motorcycle = VehicleFactory::newMotorcycle("Harley Davidson");
    std::cout << "Created vehicle: " << motorcycle.name << std::endl; 

    return 0;
}