#pragma once
struct Location;

enum Keys
{
    KB_Escape = 27,
    SpecialKey = 224,
    king = 0,
    mage = 1,
    warrior = 2,
    thief = 3,
};

enum SpecialKeys
{
    KB_Up = 72,
    KB_Down = 80,
    KB_Left = 75,
    KB_Right = 77,
};

bool handleRegularKey(int c);
void handleSpecialKey(Location& loc);