#include "timer.hpp"

Timer::Timer() : isRunning(false) {}

void Timer::start() {
    isRunning = true;
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    isRunning = false;
}

std::string Timer::getElapsedTime() const {
        if (!isRunning) {
            return "00:00";
        }

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<int> elapsedSeconds = 
            std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);

        int minutes = elapsedSeconds.count() / 60;
        int seconds = elapsedSeconds.count() % 60;

        // Format as MM:SS
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;
        return oss.str();
    }
