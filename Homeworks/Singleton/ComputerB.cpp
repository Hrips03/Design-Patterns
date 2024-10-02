#include "ComputerB.hpp"

void ComputerB::printDocument(const std::string &document)
{
    std::shared_ptr<Printer> printer = Printer::getInstance();
    std::cout << "Computer B is printing: " << document << "\n";
}
