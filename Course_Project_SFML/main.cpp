// main.cpp
#include "MinesweeperController.hpp"
#include "MinesweeperModel.hpp"
#include "MinesweeperView.hpp"

#include "MinesweeperController.hpp"

int main()
{
    MinesweeperController controller(9, 9, 10);
    controller.run();
    return 0;
}
