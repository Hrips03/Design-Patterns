#pragma once
#include "Ibook.hpp"
#include <vector>

class BookTrilogy : public IBook
{
    std::vector<IBook*> books;

     public:
        int getPrice() override;
        void addBook(IBook* book);
};