#pragma once
#include "Cell.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "Pair.h"
#include "ePatternType.h"
#include "Patterns.h"

using namespace bn;

class Simulation
{
public:
    Simulation();
    void Update();
    void Draw();
    void Clear();
    void Fill(ePatternType patternType);
    inline void Start();
    inline void Stop();

private:
    enum
    {
        ROW_COUNT = 20,
        COL_COUNT = 30,
        CELL_COUNT = 120,
        SEED_COUNT = 10,
        TEXT_COUNT = 32,
    };
    sprite_text_generator mTextGenerator;
    vector<Pair, 8> mNeighbourOffsets;

    bool mbRunning;
    bool mGrid[ROW_COUNT][COL_COUNT];
    bool mTempGrid[ROW_COUNT][COL_COUNT];
    Cell mCells[CELL_COUNT];
    size_t mCellIndex;
    vector<unsigned int, SEED_COUNT> mRandomSeeds;
    vector<bn::sprite_ptr, TEXT_COUNT> mTextSprites;
    Patterns mPatterns;

    void updateText(const char* text);
    void updateGrid();
    void setState(int row, int col, bool state);
    bool getState(int row, int col) const;
    bool isWithinBound(int row, int col) const;
    int countLiveNeighbours(int row, int col);
    void fillRandom();
};

inline void Simulation::Start()
{
    mbRunning = true;
}

inline void Simulation::Stop()
{
    mbRunning = false;
}
