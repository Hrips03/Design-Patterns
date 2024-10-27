#include "selector.hpp"

void selector(const std::string& difficulty){
    if(difficulty == "Easy" || difficulty == "easy"){
        GridFactory *easyFactory = new EasyGridFactory(); 
        IGrid *easyGrid = easyFactory->createGrid();  
        easyGrid->draw();
    }
    else if(difficulty == "Medium" || difficulty == "medium"){
        GridFactory *mediumFactory = new MediumGridFactory(); 
        IGrid *meidumGrid = mediumFactory->createGrid();  
        meidumGrid->draw();
    }
    else if(difficulty == "Hard" || difficulty == "hard"){
        GridFactory *hardFactory = new HardGridFactory(); 
        IGrid *hardGrid = hardFactory->createGrid();  
        hardGrid->draw();
    }
}