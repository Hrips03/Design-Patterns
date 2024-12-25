#pragma once
#include "../model/MinesweeperModel.hpp"
#include "../view/MinesweeperView.hpp"
#include "../model/database.hpp"
#include "MenuController.hpp"

class MinesweeperController
{
private:
    MinesweeperModel model;
    MinesweeperView view;
    std::vector<std::string> m_userInfo;

public:
    MinesweeperController(int rows, int cols, int mines, std::vector<std::string> userInfo);
    void run();
};
