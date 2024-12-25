#pragma once
#include "../model/MinesweeperModel.hpp"
#include "../view/MinesweeperView.hpp"

class MinesweeperController
{
private:
    MinesweeperModel model;
    MinesweeperView view;
    
public:
    MinesweeperController(int rows, int cols, int mines);
    void run();
};

