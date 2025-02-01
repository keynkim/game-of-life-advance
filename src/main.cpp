#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_cell.h"

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(5, 5, 5));
    bn::sprite_ptr sprite = bn::sprite_items::cell.create_sprite(-116, -76);
    while(true)
    {
        bn::core::update();
    }
}
