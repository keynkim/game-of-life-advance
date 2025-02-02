#include "Simulation.h"
#include "bn_random.h"

Simulation::Simulation()
    : mCellIndex(0)
{
    mNeighbourOffsets.push_back({ -1, 0 });	// Directly above
    mNeighbourOffsets.push_back({ 1, 0 });	// Directly below
    mNeighbourOffsets.push_back({ 0, -1 });	// To the left
    mNeighbourOffsets.push_back({ 0, 1 });	// To the right
    mNeighbourOffsets.push_back({ -1, -1 });// Diagonal upper left
    mNeighbourOffsets.push_back({ -1, 1 });	// Diagonal upper right
    mNeighbourOffsets.push_back({ 1, -1 });	// Diagonal lower left
    mNeighbourOffsets.push_back({ 1, 1 });	// Diagonal lower right
}

void Simulation::Update()
{
    // Update Temp Grid
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            int liveNeighbours = countLiveNeighbours(row, col);
            bool cellState = GetState(row, col);

            if (cellState)
            {
                // Rule 1 & 2 & 3
                if (liveNeighbours > 3 || liveNeighbours < 2)
                {
                    SetState(row, col, false);
                }
                else
                {
                    SetState(row, col, true);
                }
            }
            else
            {
                // Rule 4
                if (liveNeighbours == 3)
                {
                    SetState(row, col, true);
                }
                else
                {
                    SetState(row, col, false);
                }
            }
        }
    }

    updateGrid();
}

void Simulation::Draw()
{
    for (size_t i = 0; i < CELL_COUNT; ++i)
    {
        mCells[mCellIndex].SetActive(false);
    }

    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            if(mGrid[row][col] == true)
            {
                if (mCellIndex < CELL_COUNT)
                {
                    mCells[mCellIndex].SetGridPosition(row, col);
                    mCells[mCellIndex].SetActive(true);
                    mCellIndex++;
                }
            }
        }
    }
}

void Simulation::FillRandom()
{
    bn::random random;
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            bool isCellLive = random.get_unbiased_int(6) == 0;
            mGrid[row][col] = isCellLive;
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

void Simulation::SetState(int row, int col, bool state)
{
    if (IsWithinBound(row, col))
    {
        mTempGrid[row][col] = state;
    }
}

bool Simulation::GetState(int row, int col) const
{
    return mGrid[row][col];
}

bool Simulation::IsWithinBound(int row, int col) const
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
        int neighbourRow = (row + offset.row + ROW_COUNT) % ROW_COUNT;
        int neighbourColumn = (col + offset.col + COL_COUNT) % COL_COUNT;
        liveNeighbours += GetState(neighbourRow, neighbourColumn) == true? 1 : 0;
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
