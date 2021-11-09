#include <iostream>
#include "special_keys.h"

//-------------using section-------------------
using std::cout;

//---------------------------------------------------------------------

//functin to handle the escape key (EXIT)
bool handleRegularKey(int c)
{
    switch (c)
    {
    case KB_Escape:
        cout << "Escape pressed. Exiting...\n";
        return true;
    default:
        break;
    }

    return false;
}
