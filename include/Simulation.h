#pragma once
#include "Cell.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "Pair.h"
#include "ePattern.h"
#include "Patterns.h"

using namespace bn;

class Simulation
{
public:
    Simulation();
    void Update();
    void Draw();
    void Reset();
    void FillRandom();
    void Fill(ePatternType patternType);
    inline bool IsRunning() const;
    inline void Start();
    inline void Stop();

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
    bool mbRunning;

    sprite_text_generator mTextGenerator;
    vector<bn::sprite_ptr, TEXT_COUNT> mTextSprites;
    Patterns mPatterns;

    void clear();
    void updateText(const char* text);
    void setState(int row, int col, bool state);
    bool getState(int row, int col) const;
    bool isWithinBound(int row, int col) const;
    int countLiveNeighbours(int row, int col);
    void updateGrid();

};

inline bool Simulation::IsRunning() const
{
    return mbRunning;
}

inline void Simulation::Start()
{
    mbRunning = true;
}

inline void Simulation::Stop()
{
    mbRunning = false;
}
