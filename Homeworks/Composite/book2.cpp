#include "book2.hpp"

int Book2::getPrice()
{
    return price;
}

void Book2::setPrice(int price)
{
    this->price = price;
}

std::string Book2::getName() 
{
    return name;
}

void Book2::setName(std::string name) 
{
    this->name = name;
}