#include "Grid.h"
#include "bn_random.h"

Grid::Grid()
    : mCellIndex(0)
{
    bn::random random;
    for (size_t row = 0; row < ROW_COUNT; ++row)
    {
        for (size_t col = 0; col < COL_COUNT; ++col)
        {
            bool isCellLive = random.get_unbiased_int(6) == 0;
            mCellStates[row][col] = isCellLive? 1 : 0;

            if(isCellLive == true)
            {
                if (mCellIndex < CELL_COUNT_MAX)
                {
                    mCells[mCellIndex].SetGridPosition(row, col);
                    mCells[mCellIndex].SetActive(true);
                    mCellIndex++;
                }
            }
        }
    }
}
