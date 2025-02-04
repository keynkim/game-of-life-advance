#pragma once
#include "bn_vector.h"
#include "Pair.h"
#include "ePatternType.h"

class Patterns
{
public:
    Patterns();
    bn::vector<Pair, 40> GetPatternWithOffest(ePatternType patternType, int offsetRow, int offsetCol);
private:
    enum { PATTERN_COUNT = 40 };
    bn::vector<Pair, PATTERN_COUNT> mBlinkerFuse;
    bn::vector<Pair, PATTERN_COUNT> mPentadecathlon;
    bn::vector<Pair, PATTERN_COUNT> mDart;
};
