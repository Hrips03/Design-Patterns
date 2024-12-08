#pragma once
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>

class Timer
{
public:
    Timer();
    void start();
    void stop();
    std::string getElapsedTime() const;

private:
    bool isRunning;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};
