#pragma once
#include "io.h"
#include <conio.h>

enum Keys
{
    KB_Escape = 27,
    SpecialKey = 224,
};

enum SpecialKeys
{
    KB_Up = 72,
    KB_Down = 80,
    KB_Left = 75,
    KB_Right = 77,
};

//void handleSpecialKey();
bool handleRegularKey(int c);