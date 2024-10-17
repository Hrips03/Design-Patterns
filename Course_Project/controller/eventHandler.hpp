#include "menu.hpp"

class eventHandler : public Menu
{
    std::string choice;
public:
    eventHandler();
    void getMenuChoice();
    bool handleMenuChoice() override;
};