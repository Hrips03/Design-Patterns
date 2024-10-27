#pragma once
#include "eventHandler.hpp"

class Controller
{
    bool m_isRunning = true;
public:
    void run();
    void exit();
};
