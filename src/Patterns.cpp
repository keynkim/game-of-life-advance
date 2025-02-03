#include "Patterns.h"

Patterns::Patterns()
{
    // Blinker Fuse
    mBlinkerFuse.push_back(Pair{0, 0});
    mBlinkerFuse.push_back(Pair{1, 0});
    mBlinkerFuse.push_back(Pair{4, 0});
    mBlinkerFuse.push_back(Pair{6, 0});
    mBlinkerFuse.push_back(Pair{7, 0});
    mBlinkerFuse.push_back(Pair{0, 1});
    mBlinkerFuse.push_back(Pair{1, 1});
    mBlinkerFuse.push_back(Pair{2, 1});
    mBlinkerFuse.push_back(Pair{3, 1});
    mBlinkerFuse.push_back(Pair{4, 1});
    mBlinkerFuse.push_back(Pair{6, 1});
    mBlinkerFuse.push_back(Pair{8, 1});
    mBlinkerFuse.push_back(Pair{8, 2});
    mBlinkerFuse.push_back(Pair{10, 2});
    mBlinkerFuse.push_back(Pair{11, 2});
    mBlinkerFuse.push_back(Pair{12, 2});
    mBlinkerFuse.push_back(Pair{14, 2});
    mBlinkerFuse.push_back(Pair{15, 2});
    mBlinkerFuse.push_back(Pair{16, 2});
    mBlinkerFuse.push_back(Pair{18, 2});
    mBlinkerFuse.push_back(Pair{19, 2});
    mBlinkerFuse.push_back(Pair{20, 2});
    mBlinkerFuse.push_back(Pair{0, 3});
    mBlinkerFuse.push_back(Pair{1, 3});
    mBlinkerFuse.push_back(Pair{2, 3});
    mBlinkerFuse.push_back(Pair{3, 3});
    mBlinkerFuse.push_back(Pair{4, 3});
    mBlinkerFuse.push_back(Pair{6, 3});
    mBlinkerFuse.push_back(Pair{8, 3});
    mBlinkerFuse.push_back(Pair{0, 4});
    mBlinkerFuse.push_back(Pair{1, 4});
    mBlinkerFuse.push_back(Pair{4, 4});
    mBlinkerFuse.push_back(Pair{6, 4});
    mBlinkerFuse.push_back(Pair{7, 4});

    // Noah's Ark
    mNoahsArk.push_back(Pair{10, 0});
    mNoahsArk.push_back(Pair{12, 0});
    mNoahsArk.push_back(Pair{9, 1});
    mNoahsArk.push_back(Pair{10, 2});
    mNoahsArk.push_back(Pair{13, 2});
    mNoahsArk.push_back(Pair{12, 3});
    mNoahsArk.push_back(Pair{13, 3});
    mNoahsArk.push_back(Pair{14, 3});
    mNoahsArk.push_back(Pair{1, 9});
    mNoahsArk.push_back(Pair{0, 10});
    mNoahsArk.push_back(Pair{2, 10});
    mNoahsArk.push_back(Pair{0, 12});
    mNoahsArk.push_back(Pair{3, 12});
    mNoahsArk.push_back(Pair{2, 13});
    mNoahsArk.push_back(Pair{3, 13});
    mNoahsArk.push_back(Pair{3, 14});

    // Pentadecathlon
    mPentadecathlon.push_back(Pair{1, 0});
    mPentadecathlon.push_back(Pair{1, 1});
    mPentadecathlon.push_back(Pair{0, 2});
    mPentadecathlon.push_back(Pair{2, 2});
    mPentadecathlon.push_back(Pair{1, 3});
    mPentadecathlon.push_back(Pair{1, 4});
    mPentadecathlon.push_back(Pair{1, 5});
    mPentadecathlon.push_back(Pair{1, 6});
    mPentadecathlon.push_back(Pair{0, 7});
    mPentadecathlon.push_back(Pair{2, 7});
    mPentadecathlon.push_back(Pair{1, 8});
    mPentadecathlon.push_back(Pair{1, 9});

    // Dart
    mDart.push_back(Pair{1,0});
    mDart.push_back(Pair{0,1});
    mDart.push_back(Pair{2,1});
    mDart.push_back(Pair{0,2});
    mDart.push_back(Pair{3,2});
    mDart.push_back(Pair{2,3});
    mDart.push_back(Pair{0,4});
    mDart.push_back(Pair{1,4});
    mDart.push_back(Pair{2,4});
    mDart.push_back(Pair{3,4});
    mDart.push_back(Pair{1,5});
    mDart.push_back(Pair{3,5});
    mDart.push_back(Pair{4,5});
    mDart.push_back(Pair{6,5});
    mDart.push_back(Pair{0,6});
    mDart.push_back(Pair{1,6});
    mDart.push_back(Pair{2,6});
    mDart.push_back(Pair{7,6});
    mDart.push_back(Pair{8,6});
    mDart.push_back(Pair{7,7});
    mDart.push_back(Pair{8,7});
    mDart.push_back(Pair{0,8});
    mDart.push_back(Pair{1,8});
    mDart.push_back(Pair{2,8});
    mDart.push_back(Pair{7,8});
    mDart.push_back(Pair{8,8});
    mDart.push_back(Pair{1,9});
    mDart.push_back(Pair{3,9});
    mDart.push_back(Pair{4,9});
    mDart.push_back(Pair{6,9});
    mDart.push_back(Pair{0,10});
    mDart.push_back(Pair{1,10});
    mDart.push_back(Pair{2,10});
    mDart.push_back(Pair{3,10});
    mDart.push_back(Pair{2,11});
    mDart.push_back(Pair{0,12});
    mDart.push_back(Pair{3,12});
    mDart.push_back(Pair{0,13});
    mDart.push_back(Pair{2,13});
    mDart.push_back(Pair{1,14});
}
bn::vector<Pair, 40> Patterns::GetPatternWithOffest(ePatternType patternType, int offsetRow, int offsetCol)
{
    bn::vector<Pair, 40> pattern;
    switch(patternType)
    {
    case ePatternType::BlinkerFuse:
        pattern = mBlinkerFuse;
        break;
    case ePatternType::NoahsArk:
        pattern = mNoahsArk;
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
            pattern[i].row += offsetRow;
            pattern[i].col += offsetCol;
        }
    }

    return pattern;
}
