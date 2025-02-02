#pragma once
#include "Cell.h"
#include "bn_vector.h"
#include "Pair.h"

using namespace bn;

class Simulation
{
public:
    Simulation();
    void Update();
    void Draw();
    void FillRandom();
    void Clear();
    void SetState(int row, int col, bool state);
    bool GetState(int row, int col) const;
    bool IsWithinBound(int row, int col) const;

private:
    enum
    {
        ROW_COUNT = 20,
        COL_COUNT = 30,
        CELL_COUNT = 120,
        OFFSET_COUNT = 8
    };
    vector<Pair, 8> mNeighbourOffsets;
    bool mGrid[ROW_COUNT][COL_COUNT];
    bool mTempGrid[ROW_COUNT][COL_COUNT];
    size_t mCellIndex;
    Cell mCells[CELL_COUNT];

    int countLiveNeighbours(int row, int col);
    void updateGrid();
};
