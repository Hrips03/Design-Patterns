#include "Printer.hpp"

Printer::Printer()
{
    std::cout << "Instance of printer is created!\n";
}

std::shared_ptr<Printer> Printer::getInstance()
{
    if (!Printer::instance)
    {
        Printer::instance = std::shared_ptr<Printer>(new Printer());
    }
    return Printer::instance;
}

std::shared_ptr<Printer> Printer::instance = nullptr;