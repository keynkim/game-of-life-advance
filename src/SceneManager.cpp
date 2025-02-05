#include "SceneManager.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_title.h"
#include "bn_regular_bg_items_boundary.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_items_selector.h"
#include "common_variable_8x8_sprite_font.h"
#include "bn_vector.h"
#include "Simulation.h"

using namespace bn;

ePatternType SceneManager::sPatternType = ePatternType::Random;

void SceneManager::LoadAttractLoop()
{
    int offset = 12;
    int initialPositionX = 56;
    int initialPositionY = 24;

    regular_bg_ptr title = regular_bg_items::title.create_bg(0, 0);
    sprite_text_generator textGenerator(common::variable_8x8_sprite_font);
    textGenerator.set_center_alignment();

    sprite_ptr rightSelector = sprite_items::selector.create_sprite(initialPositionX, initialPositionY);
    sprite_ptr leftSelector = sprite_items::selector.create_sprite(-initialPositionX, initialPositionY);

    vector<bn::sprite_ptr, 32> textSprites;
    textGenerator.generate(0, initialPositionY + offset * 0, "RANDOM PATTERN", textSprites);
    textGenerator.generate(0, initialPositionY + offset * 1, "BLINKER FUSE", textSprites);
    textGenerator.generate(0, initialPositionY + offset * 2, "PENTADECATHLON", textSprites);
    textGenerator.generate(0, initialPositionY + offset * 3, "DART", textSprites);

    bool bSelectorSpriteSwitch = true;
    sprite_tiles_ptr spriteOne = sprite_items::selector.tiles_item().create_tiles(0);
    sprite_tiles_ptr spriteTwo = sprite_items::selector.tiles_item().create_tiles(1);
    leftSelector.set_tiles(spriteOne);
    rightSelector.set_tiles(spriteOne);

    bool shouldSceneUnload = false;
    int selectionIndex = 0;


    while(shouldSceneUnload == false)
    {
        if(selectionIndex >= static_cast<int>(ePatternType::MAX))
        {
            selectionIndex = 0;
        }
        else if(selectionIndex < 0 )
        {
            selectionIndex = static_cast<int>(ePatternType::MAX) - 1;
        }

        rightSelector.set_position(initialPositionX, initialPositionY + offset * selectionIndex);
        leftSelector.set_position(-initialPositionX, initialPositionY + offset * selectionIndex);

        bSelectorSpriteSwitch = !bSelectorSpriteSwitch;
        if(bSelectorSpriteSwitch)
        {
            leftSelector.set_tiles(spriteOne);
            rightSelector.set_tiles(spriteOne);
        }
        else
        {
            leftSelector.set_tiles(spriteTwo);
            rightSelector.set_tiles(spriteTwo);
        }

        if(keypad::up_pressed())
        {
            selectionIndex--;
        }
        else if(keypad::down_pressed())
        {
            selectionIndex++;
        }
        else if(keypad::a_pressed() || keypad::start_pressed())
        {
            shouldSceneUnload = true;
        }

        bn::core::update();
    }

    sPatternType = static_cast<ePatternType>(selectionIndex);
}

void SceneManager::LoadSimulationLoop()
{
    regular_bg_ptr boundary = regular_bg_items::boundary.create_bg(0, 0);
    Simulation simulation;
    simulation.Clear();
    simulation.Fill(sPatternType);

    bool shouldSceneUnload = false;
    while(shouldSceneUnload == false)
    {
        if(bn::keypad::a_pressed())
        {
            simulation.Start();
        }

        if(bn::keypad::b_pressed())
        {
            simulation.Stop();
        }

        if(bn::keypad::start_pressed())
        {
            simulation.Stop();
            simulation.Clear();
            simulation.Fill(sPatternType);
        }

        if(bn::keypad::select_pressed())
        {
            shouldSceneUnload = true;
        }

        simulation.Update();

        simulation.Draw();
        bn::core::update();
    }
}
