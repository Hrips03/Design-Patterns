#pragma once
#include "AbstractProduct.hpp"
#include <memory>

class ElectronicDeviceFactory {
public:
    virtual std::unique_ptr<ElectronicDevice> createDevice() = 0;
    virtual ~ElectronicDeviceFactory() = default;
};