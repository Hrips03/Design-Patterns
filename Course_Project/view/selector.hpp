#pragma once
#include <string>
#include "IGrid.hpp"
#include "Grids.hpp"
#include "GridFactory.hpp"
#include "GridsFactories.hpp"

IGrid* selector(const std::string& difficulty);
    