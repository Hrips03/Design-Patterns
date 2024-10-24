#include <iostream>
#include <memory>

class ElectronicDevice
{
public:
    virtual void starting() = 0;
    virtual ~ElectronicDevice() = default;
};


class Accessory
{
public:
    virtual void usingAccessory() = 0;
    virtual ~Accessory() = default;
};


class SmartPhone : public ElectronicDevice
{
public:
    void starting() override
    {
        std::cout << "Starting a Smartphone\n";
    }
};


class Tablet : public ElectronicDevice
{
public:
    void starting() override
    {
        std::cout << "Starting a Tablet\n";
    }
};


class Laptop : public ElectronicDevice
{
public:
    void starting() override
    {
        std::cout << "Starting a Laptop\n";
    }
};


class SmartPhoneCase : public Accessory
{
public:
    void usingAccessory() override
    {
        std::cout << "Using a Smartphone Case\n";
    }
};


class TabletCase : public Accessory
{
public:
    void usingAccessory() override
    {
        std::cout << "Using a Tablet Case\n";
    }
};

class LaptopCase : public Accessory
{
public:
    void usingAccessory() override
    {
        std::cout << "Using a Laptop Case\n";
    }
};


class ElectronicDeviceFactory
{
public:
    virtual std::unique_ptr<ElectronicDevice> createDevice() = 0;
    virtual std::unique_ptr<Accessory> createAccessory() = 0;
    virtual ~ElectronicDeviceFactory() = default;
};


class SmartPhoneFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override
    {
        return std::make_unique<SmartPhone>();
    }

    std::unique_ptr<Accessory> createAccessory() override
    {
        return std::make_unique<SmartPhoneCase>();
    }
};


class TabletFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override
    {
        return std::make_unique<Tablet>();
    }

    std::unique_ptr<Accessory> createAccessory() override
    {
        return std::make_unique<TabletCase>();
    }
};


class LaptopFactory : public ElectronicDeviceFactory
{
public:
    std::unique_ptr<ElectronicDevice> createDevice() override
    {
        return std::make_unique<Laptop>();
    }

    std::unique_ptr<Accessory> createAccessory() override
    {
        return std::make_unique<LaptopCase>();
    }
};

int main()
{
  
    std::unique_ptr<ElectronicDeviceFactory> smartphoneFactory = std::make_unique<SmartPhoneFactory>();
    std::unique_ptr<ElectronicDevice> smartphone = smartphoneFactory->createDevice();
    std::unique_ptr<Accessory> smartphoneCase = smartphoneFactory->createAccessory();

   
    std::unique_ptr<ElectronicDeviceFactory> tabletFactory = std::make_unique<TabletFactory>();
    std::unique_ptr<ElectronicDevice> tablet = tabletFactory->createDevice();
    std::unique_ptr<Accessory> tabletCase = tabletFactory->createAccessory();

 
    std::unique_ptr<ElectronicDeviceFactory> laptopFactory = std::make_unique<LaptopFactory>();
    std::unique_ptr<ElectronicDevice> laptop = laptopFactory->createDevice();
    std::unique_ptr<Accessory> laptopCase = laptopFactory->createAccessory();

    smartphone->starting();
    smartphoneCase->usingAccessory();

    tablet->starting();
    tabletCase->usingAccessory();

    laptop->starting();
    laptopCase->usingAccessory();

    return 0;
}
