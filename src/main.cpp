#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_cell.h"
#include "Grid.h"

using namespace bn;

int main()
{
    const color BG_COLOR = color(5, 5, 5);
    core::init();
    bg_palettes::set_transparent_color(BG_COLOR);
    Grid grid;
    while(true)
    {
        bn::core::update();
    }
}
