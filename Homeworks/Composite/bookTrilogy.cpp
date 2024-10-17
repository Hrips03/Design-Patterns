#include "bookTrilogy.hpp"

int BookTrilogy::getPrice()
{
    int result = 0;
    for (auto &&i : books)
        result += i->getPrice();

    return result;
}

std::string BookTrilogy::getName()
{
    return name;
}

void BookTrilogy::setName(std::string name)
{
    this->name = name;
}

void BookTrilogy::addBook(IBook* book)
{
    books.push_back(book);
}
