#include "./controller/MinesweeperController.hpp"
#include "./controller/MenuController.hpp"

int main()
{
    while (true) 
    {
        MenuController menu;
        std::vector<int> dimensions = menu.setMenu();
        std::vector<std::string> userInfo = menu.getUserInfo();
        
        if (dimensions.empty()) 
            break;
        
        MinesweeperController controller(dimensions[0], dimensions[1], dimensions[2], userInfo);
        controller.run();
    }

    return 0;
}
