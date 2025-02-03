#include "Patterns.h"
#include <cassert>

Patterns::Patterns()
{
    // Blinker Fuse
    mBlinkerFuse.push_back(Pair{0, 0});
    mBlinkerFuse.push_back(Pair{0, 1});
    mBlinkerFuse.push_back(Pair{0, 4});
    mBlinkerFuse.push_back(Pair{0, 6});
    mBlinkerFuse.push_back(Pair{0, 7});
    mBlinkerFuse.push_back(Pair{1, 0});
    mBlinkerFuse.push_back(Pair{1, 1});
    mBlinkerFuse.push_back(Pair{1, 2});
    mBlinkerFuse.push_back(Pair{1, 3});
    mBlinkerFuse.push_back(Pair{1, 4});
    mBlinkerFuse.push_back(Pair{1, 6});
    mBlinkerFuse.push_back(Pair{1, 8});
    mBlinkerFuse.push_back(Pair{2, 8});
    mBlinkerFuse.push_back(Pair{2, 10});
    mBlinkerFuse.push_back(Pair{2, 11});
    mBlinkerFuse.push_back(Pair{2, 12});
    mBlinkerFuse.push_back(Pair{2, 14});
    mBlinkerFuse.push_back(Pair{2, 15});
    mBlinkerFuse.push_back(Pair{2, 16});
    mBlinkerFuse.push_back(Pair{2, 18});
    mBlinkerFuse.push_back(Pair{2, 19});
    mBlinkerFuse.push_back(Pair{2, 20});
    mBlinkerFuse.push_back(Pair{3, 0});
    mBlinkerFuse.push_back(Pair{3, 1});
    mBlinkerFuse.push_back(Pair{3, 2});
    mBlinkerFuse.push_back(Pair{3, 3});
    mBlinkerFuse.push_back(Pair{3, 4});
    mBlinkerFuse.push_back(Pair{3, 6});
    mBlinkerFuse.push_back(Pair{3, 8});
    mBlinkerFuse.push_back(Pair{4, 0});
    mBlinkerFuse.push_back(Pair{4, 1});
    mBlinkerFuse.push_back(Pair{4, 4});
    mBlinkerFuse.push_back(Pair{4, 6});
    mBlinkerFuse.push_back(Pair{4, 7});

    // Pentadecathlon
    mPentadecathlon.push_back(Pair{0, 1});
    mPentadecathlon.push_back(Pair{1, 1});
    mPentadecathlon.push_back(Pair{2, 0});
    mPentadecathlon.push_back(Pair{2, 2});
    mPentadecathlon.push_back(Pair{3, 1});
    mPentadecathlon.push_back(Pair{4, 1});
    mPentadecathlon.push_back(Pair{5, 1});
    mPentadecathlon.push_back(Pair{6, 1});
    mPentadecathlon.push_back(Pair{7, 0});
    mPentadecathlon.push_back(Pair{7, 2});
    mPentadecathlon.push_back(Pair{8, 1});
    mPentadecathlon.push_back(Pair{9, 1});

    // Dart
    mDart.push_back(Pair{0, 1});
    mDart.push_back(Pair{1, 0});
    mDart.push_back(Pair{1, 2});
    mDart.push_back(Pair{2, 0});
    mDart.push_back(Pair{2, 3});
    mDart.push_back(Pair{3, 2});
    mDart.push_back(Pair{4, 0});
    mDart.push_back(Pair{4, 1});
    mDart.push_back(Pair{4, 2});
    mDart.push_back(Pair{4, 3});
    mDart.push_back(Pair{5, 1});
    mDart.push_back(Pair{5, 3});
    mDart.push_back(Pair{5, 4});
    mDart.push_back(Pair{5, 6});
    mDart.push_back(Pair{6, 0});
    mDart.push_back(Pair{6, 1});
    mDart.push_back(Pair{6, 2});
    mDart.push_back(Pair{6, 7});
    mDart.push_back(Pair{6, 8});
    mDart.push_back(Pair{7, 7});
    mDart.push_back(Pair{7, 8});
    mDart.push_back(Pair{8, 0});
    mDart.push_back(Pair{8, 1});
    mDart.push_back(Pair{8, 2});
    mDart.push_back(Pair{8, 7});
    mDart.push_back(Pair{8, 8});
    mDart.push_back(Pair{9, 1});
    mDart.push_back(Pair{9, 3});
    mDart.push_back(Pair{9, 4});
    mDart.push_back(Pair{9, 6});
    mDart.push_back(Pair{10, 0});
    mDart.push_back(Pair{10, 1});
    mDart.push_back(Pair{10, 2});
    mDart.push_back(Pair{10, 3});
    mDart.push_back(Pair{11, 2});
    mDart.push_back(Pair{12, 0});
    mDart.push_back(Pair{12, 3});
    mDart.push_back(Pair{13, 0});
    mDart.push_back(Pair{13, 2});
    mDart.push_back(Pair{14, 1});
}

// Pre-condition: Do not use ePatternType::Random
bn::vector<Pair, 40> Patterns::GetPatternWithOffest(ePatternType patternType, int offsetRow, int offsetCol)
{
    bn::vector<Pair, 40> pattern;
    switch(patternType)
    {
    case ePatternType::Random:
        assert(false);
        break;
    case ePatternType::BlinkerFuse:
        pattern = mBlinkerFuse;
        break;
    case ePatternType::Pentadecathlon:
        pattern = mPentadecathlon;
        break;
    case ePatternType::Dart:
        pattern = mDart;
        break;
    default:
        break;
    }

    if(offsetRow != 0 || offsetCol != 0)
    {
        for(int i = 0; i < pattern.size(); ++i)
        {
            pattern[i].First += offsetRow;
            pattern[i].Second += offsetCol;
        }
    }

    return pattern;
}
