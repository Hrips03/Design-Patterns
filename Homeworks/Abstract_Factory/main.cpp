#include "ConcreteFactories.hpp"
#include "ConcreteProducts.hpp"

int main() {
    // Create factories
    std::unique_ptr<ElectronicDeviceFactory> smartPhoneFactory = std::make_unique<SmartPhoneFactory>();
    std::unique_ptr<ElectronicDeviceFactory> tabletFactory = std::make_unique<TabletFactory>();
    std::unique_ptr<ElectronicDeviceFactory> laptopFactory = std::make_unique<LaptopFactory>();

    // Create products using the factories
    std::unique_ptr<ElectronicDevice> smartphone = smartPhoneFactory->createDevice();
    std::unique_ptr<ElectronicDevice> tablet = tabletFactory->createDevice();
    std::unique_ptr<ElectronicDevice> laptop = laptopFactory->createDevice();

    // Use the devices
    smartphone->starting();
    tablet->starting();
    laptop->starting();

    return 0;
}
