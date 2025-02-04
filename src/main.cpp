#include "bn_core.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"
#include "SceneManager.h"
using namespace bn;

int main()
{
    core::init();
    core::set_skip_frames(3);
    const color BG_COLOR = color(5, 5, 5);
    bg_palettes::set_transparent_color(BG_COLOR);

    while(true)
    {
        SceneManager::LoadAttractLoop();

        SceneManager::LoadSimulationLoop();

        bn::core::update();
    }
}
