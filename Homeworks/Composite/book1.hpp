#pragma once
#include "Ibook.hpp"

class Book1 : public IBook
{
    int price = 0;
    std::string name;

    public:
        int getPrice() override;
        void setPrice(int price);

        std::string getName() override;
        void setName(std::string name) override;
};
