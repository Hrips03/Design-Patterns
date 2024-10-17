#pragma once
#include <string>

class IBook
{
  int price = 0;
  std::string name;
  
public:
    virtual int getPrice();
    virtual std::string getName();
    virtual void setName(std::string name);  
    virtual void setPrice(int price);

    virtual ~IBook() = default;
};