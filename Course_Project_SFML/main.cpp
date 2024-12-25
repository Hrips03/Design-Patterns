// main.cpp
#include "./controller/MinesweeperController.hpp"
#include "./model/MinesweeperModel.hpp"
#include "./view/MinesweeperView.hpp"

int main()
{
    MinesweeperController controller(9, 9, 10);
    controller.run();
    return 0;
}
