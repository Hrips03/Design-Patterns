#include "Printer.hpp"
#include "ComputerA.hpp"
#include "ComputerB.hpp"

int main()
{
    ComputerA computerA;
    ComputerB computerB;

    computerA.printDocument("Document from Computer A");
    computerB.printDocument("Document from Computer B");

    return 0;
}
