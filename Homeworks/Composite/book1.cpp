#include "book1.hpp"

int Book1::getPrice()
{
    return price;
}

void Book1::setPrice(int price)
{
    this->price = price;
}

std::string Book1::getName() 
{
    return name;
}

void Book1::setName(std::string name) 
{
    this->name = name;
}