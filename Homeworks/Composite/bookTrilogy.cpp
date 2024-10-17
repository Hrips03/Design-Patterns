#include "bookTrilogy.hpp"

int BookTrilogy::getPrice()
{
    int result = 0;
    for (auto &&i : books)
        result += i->getPrice();

    return result;
}

void BookTrilogy::addBook(IBook* book)
{
    books.push_back(book);
}
