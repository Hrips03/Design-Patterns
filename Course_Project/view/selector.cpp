#include "selector.hpp"

IGrid* selector(const std::string& difficulty) {
    if (difficulty == "Easy" || difficulty == "easy") {
        GridFactory* easyFactory = new EasyGridFactory();
        //easyFactory->createEmptyGrid();
        //easyFactory->generateGrid();
        return easyFactory->createEmptyGrid();

    } 
    else if (difficulty == "Medium" || difficulty == "medium") {
        GridFactory* mediumFactory = new MediumGridFactory();
        return mediumFactory->createEmptyGrid();
    } 
    else if (difficulty == "Hard" || difficulty == "hard") {
        GridFactory* hardFactory = new HardGridFactory();
        return hardFactory->createEmptyGrid();
    } 
    return nullptr;
}