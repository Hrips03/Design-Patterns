#include "selector.hpp"

IGrid* selector(const std::string& difficulty) {
    if (difficulty == "Easy" || difficulty == "easy") {
        GridFactory* easyFactory = new EasyGridFactory();
        return easyFactory->createGrid();
    } 
    else if (difficulty == "Medium" || difficulty == "medium") {
        GridFactory* mediumFactory = new MediumGridFactory();
        return mediumFactory->createGrid();
    } 
    else if (difficulty == "Hard" || difficulty == "hard") {
        GridFactory* hardFactory = new HardGridFactory();
        return hardFactory->createGrid();
    } 
    return nullptr;
}