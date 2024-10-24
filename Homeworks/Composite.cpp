#include <iostream>
#include <string>
#include <vector>
#include <memory>


class IBook
{
public:
    virtual int getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual void setName(const std::string &name) = 0;
    virtual void setPrice(int price) = 0;
    virtual ~IBook() = default;
};


class Book1 : public IBook
{
    int price;
    std::string name;

public:
    int getPrice() const override
    {
        return price;
    }
    std::string getName() const override
    {
        return name;
    }
    void setName(const std::string &name) override
    {
        this->name = name;
    }
    void setPrice(int price) override
    {
        this->price = price;
    }
};

class Book2 : public IBook
{
    int price;
    std::string name;

public:
    int getPrice() const override
    {
        return price;
    }
    std::string getName() const override
    {
        return name;
    }
    void setName(const std::string &name) override
    {
        this->name = name;
    }
    void setPrice(int price) override
    {
        this->price = price;
    }
};

class Book3 : public IBook
{
    int price;
    std::string name;

public:
    int getPrice() const override
    {
        return price;
    }
    std::string getName() const override
    {
        return name;
    }
    void setName(const std::string &name) override
    {
        this->name = name;
    }
    void setPrice(int price) override
    {
        this->price = price;
    }
};


class BookTrilogy : public IBook
{
    std::vector<std::shared_ptr<IBook>> books;
    std::string name;

public:
    int getPrice() const override
    {
        int totalPrice = 0;
        for (const auto &book : books)
        {
            totalPrice += book->getPrice();
        }
        return totalPrice;
    }

    std::string getName() const override
    {
        return name;
    }

    void setName(const std::string &name) override
    {
        this->name = name;
    }

    void setPrice(int) override
    {
       
    }

    void addBook(std::shared_ptr<IBook> book)
    {
        books.push_back(book);
    }
};

int main()
{
    auto book1 = std::make_shared<Book1>();
    book1->setName("The Hunger Games");
    book1->setPrice(15000);
    std::cout << "Book1_name = " << book1->getName() << "\nBook1_price = " << book1->getPrice() << "\n\n";

    auto book2 = std::make_shared<Book2>();
    book2->setName("Catching Fire");
    book2->setPrice(25000);
    std::cout << "Book2_name = " << book2->getName() << "\nBook2_price = " << book2->getPrice() << "\n\n";

    auto book3 = std::make_shared<Book3>();
    book3->setName("The Mockingjay");
    book3->setPrice(40000);
    std::cout << "Book3_name = " << book3->getName() << "\nBook3_price = " << book3->getPrice() << "\n\n";

    BookTrilogy trilogy;
    trilogy.setName("Hunger Games Trilogy");
    trilogy.addBook(book1);
    trilogy.addBook(book2);
    trilogy.addBook(book3);
    std::cout << "BookTrilogy_name = " << trilogy.getName() << "\nBookTrilogy_price = " << trilogy.getPrice() << "\n";
}
