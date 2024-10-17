#include "book3.hpp"

int Book3::getPrice()
{
    return price;
}

void Book3::setPrice(int price)
{
    this->price = price;
}

std::string Book3::getName() 
{
    return name;
}

void Book3::setName(std::string name) 
{
    this->name = name;
}