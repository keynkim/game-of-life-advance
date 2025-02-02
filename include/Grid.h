#pragma once
#include "Cell.h"

using namespace bn;

class Grid
{
public:
    Grid();


private:
    enum
    {
        CELL_SIZE = 8,
        ROW_COUNT = 20,
        COL_COUNT = 30,
        CELL_COUNT_MAX = 120
    };
    size_t mCellSize = CELL_SIZE;
    size_t mCellStates[ROW_COUNT][COL_COUNT];
    size_t mCellIndex;
    Cell mCells[CELL_COUNT_MAX];
};
