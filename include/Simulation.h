#pragma once
#include "Cell.h"
#include "bn_sprite_text_generator.h"
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
    void Reset();

private:
    enum
    {
        ROW_COUNT = 20,
        COL_COUNT = 30,
        CELL_COUNT = 120,
        OFFSET_COUNT = 8,
        TEXT_COUNT = 32
    };
    vector<Pair, 8> mNeighbourOffsets;
    bool mGrid[ROW_COUNT][COL_COUNT];
    bool mTempGrid[ROW_COUNT][COL_COUNT];
    size_t mCellIndex;
    Cell mCells[CELL_COUNT];
    bn::sprite_text_generator mTextGenerator;
    bn::vector<bn::sprite_ptr, TEXT_COUNT> mTextSprites;

    void clear();
    void updateText(const char* text);
    void setState(int row, int col, bool state);
    bool getState(int row, int col) const;
    bool isWithinBound(int row, int col) const;
    int countLiveNeighbours(int row, int col);
    void updateGrid();
};
