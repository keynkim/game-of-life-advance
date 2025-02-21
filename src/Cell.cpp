#include "Cell.h"
#include "bn_sprite_items_cell.h"
#include "bn_fixed_point.h"

Cell::Cell()
    : mSprite(bn::sprite_items::cell.create_sprite(0, 0))
{
    SetActive(false);
}

void Cell::SetActive(bool active)
{
    mSprite.set_visible(active);
}

void Cell::SetGridPosition(int row, int col)
{
    bn::fixed_point position = {PIXEL_OFFSET + col * CELL_SIZE, PIXEL_OFFSET + row * CELL_SIZE};
    mSprite.set_top_left_position(position);
}
