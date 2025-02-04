#include "Simulation.h"
#include "bn_time.h"
#include "bn_seed_random.h"
#include "bn_sprite_text_generator.h"
#include "common_variable_8x8_sprite_font.h"

Simulation::Simulation()
    : mTextGenerator(common::variable_8x8_sprite_font)
    , mbRunning(false)
{
    mTextGenerator.set_right_alignment();

    mNeighbourOffsets.push_back({ -1, 0 });	// Directly above
    mNeighbourOffsets.push_back({ 1, 0 });	// Directly below
    mNeighbourOffsets.push_back({ 0, -1 });	// To the left
    mNeighbourOffsets.push_back({ 0, 1 });	// To the right
    mNeighbourOffsets.push_back({ -1, -1 });// Diagonal upper left
    mNeighbourOffsets.push_back({ -1, 1 });	// Diagonal upper right
    mNeighbourOffsets.push_back({ 1, -1 });	// Diagonal lower left
    mNeighbourOffsets.push_back({ 1, 1 });	// Diagonal lower right

    mRandomSeeds.push_back(21312421);
    mRandomSeeds.push_back(86375927);
    mRandomSeeds.push_back(22133678);
    mRandomSeeds.push_back(26321754);
    mRandomSeeds.push_back(40082645);
    mRandomSeeds.push_back(94212078);
    mRandomSeeds.push_back(85922364);
    mRandomSeeds.push_back(41908183);
    mRandomSeeds.push_back(59093239);
}

void Simulation::updateText(const char* text)
{
    mTextSprites.clear();
    mTextGenerator.generate(118, 74, text, mTextSprites);
}

void Simulation::Update()
{
    if (mbRunning == false)
    {
        return;
    }
    // Update Temp Grid
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            int liveNeighbours = countLiveNeighbours(row, col);
            bool cellState = getState(row, col);

            if (cellState)
            {
                // Rule 1 & 2 & 3
                if (liveNeighbours > 3 || liveNeighbours < 2)
                {
                    setState(row, col, false);
                }
                else
                {
                    setState(row, col, true);
                }
            }
            else
            {
                // Rule 4
                if (liveNeighbours == 3)
                {
                    setState(row, col, true);
                }
                else
                {
                    setState(row, col, false);
                }
            }
        }
    }

    updateGrid();
}

void Simulation::Draw()
{
    size_t cellIndex = 0;
    for (size_t i = 0; i < CELL_COUNT; ++i)
    {
        mCells[i].SetActive(false);
    }

    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            if(mGrid[row][col] == true)
            {
                if (cellIndex < CELL_COUNT)
                {
                    mCells[cellIndex].SetGridPosition(row, col);
                    mCells[cellIndex].SetActive(true);
                    cellIndex++;
                }

                if(cellIndex == CELL_COUNT)
                {
                    updateText("OVERFLOW");
                }
                else
                {
                    updateText("");
                }
            }
        }
    }
}

void Simulation::Clear()
{
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            mGrid[row][col] = false;
        }
    }
}

void Simulation::fillRandom()
{
    static int seedIndex = 0;

    if(seedIndex == mRandomSeeds.size())
    {
        seedIndex = 0;
    }

    unsigned int randomSeed = mRandomSeeds[seedIndex];
    seedIndex++;

    if (time::active())
    {
        optional<bn::time> time = bn::time::current();
        randomSeed += 10000 * time->second();
        randomSeed += 100 * time->minute();
        randomSeed += time->hour();
    }

    seed_random seedRandom(randomSeed);

    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            bool isCellLive = seedRandom.get_unbiased_int(6) == 0;
            mGrid[row][col] = isCellLive;
        }
    }
}
void Simulation::Fill(ePatternType patternType)
{
    vector<Pair, 40> pattern;
    switch(patternType)
    {
    case ePatternType::Random:
        fillRandom();
        return;
        break;
    case ePatternType::BlinkerFuse:
        pattern = mPatterns.GetPatternWithOffest(patternType, 7, 1);
        break;
    case ePatternType::Pentadecathlon:
        pattern = mPatterns.GetPatternWithOffest(patternType, 4, 13);
        break;
    case ePatternType::Dart:
        pattern = mPatterns.GetPatternWithOffest(patternType, 2, 1);
        break;
    default:
        break;
    }

    for(int i = 0; i < pattern.size(); ++i)
    {
        mGrid[pattern[i].First][pattern[i].Second] = true;
    }
}

void Simulation::setState(int row, int col, bool state)
{
    if (isWithinBound(row, col))
    {
        mTempGrid[row][col] = state;
    }
}

bool Simulation::getState(int row, int col) const
{
    return mGrid[row][col];
}

bool Simulation::isWithinBound(int row, int col) const
{

    if (row >= 0 && row < ROW_COUNT && col >= 0 && col < COL_COUNT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Simulation::countLiveNeighbours(int row, int col)
{
    int liveNeighbours = 0;

    for (const auto& offset : mNeighbourOffsets)
    {
        // Toroidal Grid
        int neighbourRow = (row + offset.First + ROW_COUNT) % ROW_COUNT;
        int neighbourColumn = (col + offset.Second + COL_COUNT) % COL_COUNT;
        liveNeighbours += getState(neighbourRow, neighbourColumn) == true? 1 : 0;
    }

    return liveNeighbours;
}

void Simulation::updateGrid()
{
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            mGrid[row][col] = mTempGrid[row][col];
        }
    }
}
