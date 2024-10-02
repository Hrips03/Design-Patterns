#include "ConcreteFactories.hpp"

std::unique_ptr<ElectronicDevice> SmartPhoneFactory::createDevice()
{
    return std::make_unique<SmartPhone>();
}

std::unique_ptr<ElectronicDevice> TabletFactory::createDevice()
{
    return std::make_unique<Tablet>();
}

std::unique_ptr<ElectronicDevice> LaptopFactory::createDevice()
{
    return std::make_unique<Laptop>();
}
