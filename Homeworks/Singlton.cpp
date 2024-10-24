#include <iostream>
#include <memory>

class Printer
{
    Printer()
    {
        std::cout << "Instance of printer is created!\n";
    }

    Printer(const Printer &) = delete;
    Printer &operator=(const Printer &) = delete;

    Printer(const Printer &&) = delete;
    Printer &&operator=(const Printer &&) = delete;

    static std::shared_ptr<Printer> instance;

public:
    static std::shared_ptr<Printer> getInstance()
    {
        if (!Printer::instance)
        {
            Printer::instance = std::shared_ptr<Printer>(new Printer());
        }
        return Printer::instance;
    }
};

std::shared_ptr<Printer> Printer::instance = nullptr;

class ComputerA
{
public:
    void printDocument(const std::string &document)
    {
        std::shared_ptr<Printer> printer = Printer::getInstance();
        std::cout << "Computer A is printing: " << document << "\n";
    }
};

class ComputerB
{
public:
    void printDocument(const std::string &document)
    {
        std::shared_ptr<Printer> printer = Printer::getInstance();
        std::cout << "Computer B is printing: " << document << "\n";
    }
};

int main()
{
    ComputerA computerA;
    ComputerB computerB;

    computerA.printDocument("Document from Computer A");
    computerB.printDocument("Document from Computer B");

    return 0;
}