#include <iostream>

//Handler
class AtmHandler
{
    AtmHandler *m_succ;

public:
    AtmHandler(AtmHandler *s = nullptr) : m_succ(s) {}

    virtual void HandleRequest(int sum)
    {
        if (m_succ)
            m_succ->HandleRequest(sum);
        else if (sum > 0)
        {
            std::cerr << "Cannot dispense remaining amount: " << sum << std::endl;
        }
    }
};

//Concrete handler 1
class DramHandler : public AtmHandler
{
    int billValue;

public:
    DramHandler(int value, AtmHandler *s = nullptr) : billValue(value), AtmHandler(s) {}

    void HandleRequest(int sum)
    {
        int numOfBills = sum / billValue;
        if (sum % billValue == 0)
        {
            if (numOfBills != 0)
                std::cout << "Number of " << billValue << " drams: " << numOfBills << std::endl;
        }
        else
        {
            if (numOfBills != 0)
                std::cout << "Number of " << billValue << " drams: " << numOfBills << std::endl;

            sum = sum - numOfBills * billValue;
            AtmHandler::HandleRequest(sum);
        }
    }
};

int main()
{
    AtmHandler *atm = new AtmHandler(new DramHandler(20000, new DramHandler(10000, new DramHandler(5000, new DramHandler(1000)))));

    std::cout << "Withdraw 16000 dram" << std::endl;
    atm->HandleRequest(16000);
    std::cout << std::endl;

    std::cout << "Withdraw 67000 dram" << std::endl;
    atm->HandleRequest(67000);
}