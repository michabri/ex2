#include <iostream>
#include <conio.h>
#include "SpecialKeys.h"
#include "Location.h"
using std::cin;
using std::cout;


bool handleRegularKey(int c)
{
    switch (c)
    {
    case KB_Escape:
        std::cout << "Escape pressed. Exiting...\n";
        return true;
    default:
        break;
    }
    return false;
}

void handleSpecialKey(Location &loc)
{
    auto c = _getch();
    switch (c)
    {
    case KB_Up:
        loc.row--;
        break;
    case KB_Down:
        loc.row++;
        break;
    case KB_Left:
        loc.col--;
        break;
    case KB_Right:
        loc.col++;
        break;
    default:
        break;
    }
}