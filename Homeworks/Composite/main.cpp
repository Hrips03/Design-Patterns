#include <iostream>
#include "bookTrilogy.hpp"
#include "book1.hpp"
#include "book2.hpp"
#include "book3.hpp"

int main()
{
    Book1* book1 = new Book1();
    book1->setName("The Hunger Games");
    book1->setPrice(15000);
    std::cout << "Book1_name = " << book1->getName() << "\nBook1_price = " << book1->getPrice() << "\n\n";


    Book2* book2 = new Book2();
    book2->setName("Catching Fire");
    book2->setPrice(25000);
    std::cout << "Book2_name = " << book2->getName() << "\nBook2_price = " << book2->getPrice() << "\n\n";


    Book3* book3 = new Book3();
    book3->setName("The Mockingjay");
    book3->setPrice(40000);
    std::cout << "Book3_name = " << book3->getName() << "\nBook3_price = " << book3->getPrice() << "\n\n";


    BookTrilogy trilogy;
    trilogy.setName("Hunger Games");
    trilogy.addBook(book1);
    trilogy.addBook(book2);
    trilogy.addBook(book3);
    std::cout << "BookTrilogy_name = " << trilogy.getName() << "\nBookTrilogy_price = " << trilogy.getPrice() << "\n";
}