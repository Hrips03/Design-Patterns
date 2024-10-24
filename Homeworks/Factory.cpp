#include <iostream>
#include <memory>

class Vehicle
{
public:
    virtual void printDetails() const = 0;
    virtual ~Vehicle() = default;
};

class VehicleFactory
{
public:
    virtual Vehicle *createVehicle() = 0;
    virtual ~VehicleFactory() {}
};

class CarFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() override
    {
        return new Car();
    }
};

class Car : public Vehicle
{
public:
    void printDetails() const override
    {
        std::cout << "This is a Car." << std::endl;
    }
};

class AirplaneFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() override
    {
        return new Airplane();
    }
};
class Airplane : public Vehicle
{
public:
    void printDetails() const override
    {
        std::cout << "This is an Airplane." << std::endl;
    }
};
int main()
{
    VehicleFactory *carFactory = new CarFactory();
    VehicleFactory *motorcycleFactory = new AirplaneFactory();

    Vehicle *car = carFactory->createVehicle();
    Vehicle *airplane = motorcycleFactory->createVehicle();

    car->printDetails();
    airplane->printDetails();

    return 0;
}
