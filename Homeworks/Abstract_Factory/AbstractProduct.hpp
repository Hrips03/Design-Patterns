#pragma once

class ElectronicDevice
{
public:
    virtual void starting() = 0;
    virtual ~ElectronicDevice() = default;
};
