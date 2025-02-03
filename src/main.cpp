#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"
#include "Simulation.h"
#include "ePattern.h"

using namespace bn;

int main()
{
    core::init();
    core::set_skip_frames(2);
    const color BG_COLOR = color(5, 5, 5);
    bg_palettes::set_transparent_color(BG_COLOR);

    Simulation simulation;

    while(true)
    {
        bn::core::update();

        // Event Handling
        if(bn::keypad::pressed(bn::keypad::key_type::A))
        {
            simulation.Start();
        }
        if(bn::keypad::pressed(bn::keypad::key_type::B))
        {
            simulation.Stop();
        }
        if(bn::keypad::pressed(bn::keypad::key_type::UP))
        {
            simulation.Stop();
            simulation.Reset();
            simulation.Fill(ePatternType::BlinkerFuse);
        }
        if(bn::keypad::pressed(bn::keypad::key_type::DOWN))
        {
            simulation.Stop();
            simulation.Reset();
            simulation.FillRandom();
        }
        if(bn::keypad::pressed(bn::keypad::key_type::RIGHT))
        {
            simulation.Stop();
            simulation.Reset();
            simulation.Fill(ePatternType::Pentadecathlon);
        }
        if(bn::keypad::pressed(bn::keypad::key_type::LEFT))
        {
            simulation.Stop();
            simulation.Reset();
            simulation.Fill(ePatternType::Dart);
        }

        // Updating
        simulation.Update();

        // Drawing
        simulation.Draw();
    }
}
