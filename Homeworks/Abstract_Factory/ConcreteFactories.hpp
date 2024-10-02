#include "AbstractFactory.hpp"
#include "ConcreteProducts.hpp"

class SmartPhoneFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override;
};

class TabletFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override;
};

class LaptopFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override;
};