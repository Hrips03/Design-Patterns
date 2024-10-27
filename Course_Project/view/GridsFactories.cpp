#include "GridsFactories.hpp"
#include "Grids.hpp"

IGrid* EasyGridFactory ::createGrid() {
   return new EasyGrid();
}

IGrid* MediumGridFactory ::createGrid() {
    return new MediumGrid();
}

IGrid* HardGridFactory ::createGrid() {
    return new HardGrid();
}
