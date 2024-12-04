#include <iostream>
#include <memory>

// Implementor
class PaymentMethod
{
public:
    virtual void authorize() = 0;
    virtual void pay() = 0;
    virtual ~PaymentMethod() = default;
};

// Concrete implementor 1
class CreditCard : public PaymentMethod
{
public:
    void authorize() override
    {
        std::cout << "Credit Card is authorized.\n";
    }
    void pay() override
    {
        std::cout << "Payment was successful from Credit Card.\n";
    }
};

// Concrete implementor 2
class PayPal : public PaymentMethod
{
public:
    void authorize() override
    {
        std::cout << "PayPal is authorized.\n";
    }
    void pay() override
    {
        std::cout << "Payment was successful from PayPal.\n";
    }
};

// Abstraction
class PaymentCheckout
{
    std::shared_ptr<PaymentMethod> payment;

public:
    PaymentCheckout(std::shared_ptr<PaymentMethod> ptr) : payment(ptr) {}

    void pay()
    {
        payment->authorize();
        payment->pay();
    }
};


int main()
{
    auto card = std::make_shared<CreditCard>();
    auto wallet = std::make_shared<PayPal>();

    PaymentCheckout cardPayment(card);
    PaymentCheckout walletPayment(wallet);

    cardPayment.pay();
    walletPayment.pay();
}