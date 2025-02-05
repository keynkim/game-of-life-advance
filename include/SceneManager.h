#pragma once
#include "ePatternType.h"


class SceneManager
{
public:
    static void LoadAttractLoop();
    static void LoadSimulationLoop();
private:
    static ePatternType sPatternType;
};
