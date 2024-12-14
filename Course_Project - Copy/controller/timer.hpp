#pragma once
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>

class Timer
{
    bool isRunning;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
    Timer();
    void start();
    void stop();
    std::string getElapsedTime() const;
};
