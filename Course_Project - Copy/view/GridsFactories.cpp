#include "GridsFactories.hpp"
#include "Grids.hpp"

IGrid* EasyGridFactory ::createEmptyGrid() {
   return new EasyGrid();
}

IGrid* MediumGridFactory ::createEmptyGrid() {
    return new MediumGrid();
}

IGrid* HardGridFactory ::createEmptyGrid() {
    return new HardGrid();
}

