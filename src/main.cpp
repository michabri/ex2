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
    
    char player = ' ';
    int counter = 0;
    int key = 0;
    bool victory = false;
    auto exit = false;
    for (int i=0; !exit && i<3; i++)
    {
        std::cout << "Enter a level: \n";
        std::cin >> file_name;
        Board board(file_name);
        victory = false;
        player = ' ';
        while (!victory && !exit)
        {
            std::system("cls");
            board.print_board(player, counter, key);

            player = _getch();
            if (!board.check_valid_player(player))
                continue;

            std::system("cls");
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
            std::cout << "you passed level " << i+1 << "! \n";
        }
    }
}
