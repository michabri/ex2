#include <iostream>
#include <cstdlib> // for std::system()
#include "io.h"

#include <conio.h>
#include "board.h"
#include "special_keys.h"


int main()
{
    std::system("cls");

    Screen::resetLocation();

    char file_name[LENGTH];
    std::cout << "Enter a file name\n";
    std::cin >> file_name;
    
    Board board(file_name);
    char player;
    int counter = 0;
    int key = 0;
    bool victory = false;

    for (auto exit = false; !exit && !victory; )
    {
        std::cout << "choose a player" << std::endl;
        player = _getch();
        std::system("cls");
        if (!board.check_valid_player(player))
            continue;
        
        board.print_board(player, counter, key);
        
        auto input = _getch();
        std::system("cls");
        
        while (input != 'p' && !exit && !victory)
        {
            switch (input)
            {
            case SpecialKey: 
                if (board.move_player(player, victory))
                    counter++;
                break;
            default:
                exit = handleRegularKey(input);
            }
            if (!victory)
            {
                board.print_board(player, counter, board.get_key_counter());
                input = _getch();
                std::system("cls");
            }
        }
    }
    if (victory)
    {
        board.print_victory();
    }
}
