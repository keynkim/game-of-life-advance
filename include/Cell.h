#pragma once
#include "bn_sprite_ptr.h"

class Cell
{
public:
    Cell();
    void SetActive(bool active);
    void SetGridPosition(int row, int col);
private:
    bn::sprite_ptr mSprite;
};
