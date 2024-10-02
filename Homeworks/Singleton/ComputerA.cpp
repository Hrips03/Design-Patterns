#include "ComputerA.hpp"

void ComputerA::printDocument(const std::string &document)
{
    std::shared_ptr<Printer> printer = Printer::getInstance();
    std::cout << "Computer A is printing: " << document << "\n";
}
