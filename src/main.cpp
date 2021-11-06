#include <iostream>
#include <cstdlib> // for std::system()
#include "io.h"

#include <conio.h>
#include "board.h"
#include "special_keys.h"

#include "game.h"


int main()
{
    std::system("cls");

    Screen::resetLocation();

    game();
    
    exit(EXIT_SUCCESS);
}
