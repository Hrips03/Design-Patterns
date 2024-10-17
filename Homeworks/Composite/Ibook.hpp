#pragma once
#include <string>

class IBook
{
public:
    virtual int getPrice() = 0;
      virtual std::string getName() = 0;
    virtual void setName(std::string name) = 0;  

    virtual ~IBook() = default;
};