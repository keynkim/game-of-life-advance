#pragma once
#include "bn_sprite_ptr.h"

class Cell
{
public:
    Cell();
    void SetActive(bool active);
    void SetGridPosition(int row, int col);
private:
    enum
    {
        CELL_SIZE = 8,
    };
    bn::sprite_ptr mSprite;
};
