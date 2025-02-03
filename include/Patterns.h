#pragma once
#include "bn_vector.h"
#include "Pair.h"
#include "ePattern.h"
class Patterns
{
public:
    Patterns();
    bn::vector<Pair, 40> GetPatternWithOffest(ePatternType patternType, int offsetRow, int offsetCol);
private:
    bn::vector<Pair, 40> mBlinkerFuse;
    bn::vector<Pair, 40> mNoahsArk;
    bn::vector<Pair, 40> mPentadecathlon;
    bn::vector<Pair, 40> mDart;
};
