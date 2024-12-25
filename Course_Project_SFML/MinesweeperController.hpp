#pragma once
#include "MinesweeperModel.hpp"
#include "MinesweeperView.hpp"

class MinesweeperController
{
private:
    MinesweeperModel model;
    MinesweeperView view;

public:
    MinesweeperController(int rows, int cols, int mines);
    void run();
};

