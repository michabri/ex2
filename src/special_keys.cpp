#include <conio.h>
#include <iostream>
#include "special_keys.h"
#include "io.h"

//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;

//---------------------------------------------------------------------
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
