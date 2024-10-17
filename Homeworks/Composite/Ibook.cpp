#include "Ibook.hpp"

int IBook::getPrice()
{
    return price;
}

void IBook::setPrice(int price)
{
    this->price = price;
}

std::string IBook::getName() 
{
    return name;
}

void IBook::setName(std::string name) 
{
    this->name = name;
}