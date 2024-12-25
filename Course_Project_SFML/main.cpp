// main.cpp
#include "./controller/MinesweeperController.hpp"
#include "./controller/MenuController.hpp"

// int main()
// {
//     MenuController menu;
//     std::vector<int> dimensions = menu.setMenu();
//     MinesweeperController controller(dimensions[0], dimensions[1], dimensions[2]);
//     controller.run();

//     return 0;
// }

int main()
{
    while (true) // Keep looping until the user exits
    {
        MenuController menu;
        std::vector<int> dimensions = menu.setMenu();
        std::vector<std::string> userInfo = menu.getUserInfo();
        
        if (dimensions.empty()) // User chose to exit
        {
            break;
        }

        MinesweeperController controller(dimensions[0], dimensions[1], dimensions[2], userInfo);
        controller.run();
    }

    return 0;
}
