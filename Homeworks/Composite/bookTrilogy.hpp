#pragma once
#include "Ibook.hpp"
#include <vector>

class BookTrilogy : public IBook
{
    std::string name;
    std::vector<IBook*> books;

     public:
        int getPrice() override;
        std::string getName() override;
        void setName(std::string name) override;
        void addBook(IBook* book);
};