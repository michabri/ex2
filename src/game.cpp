#include <iostream>
#include <cstdlib> // for std::system()
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <conio.h>

#include "io.h"
#include "board.h"
#include "game.h"
#include "special_keys.h"

//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
//------------------------------------------------

void game()
{
    char file_name[LENGTH];
    char level_file[LENGTH];
    
    cin >> file_name;

    ifstream in;
    in.open(file_name);
    if (!in.is_open())
    {
        cerr << "could not open the file -" << file_name << endl;
        exit(EXIT_FAILURE);
    }

    char player , enter;
    int counter = 0;
    int key = 0;
    bool victory = false;
    auto exit = false;

    for (int i = 0;  !exit && !in.eof(); i++)
    {
        in.getline(level_file, LENGTH);

        Board board(level_file);
        victory = false;
        int index_player = 0;
        
        while (!victory && !exit)
        {
            player = get_player(index_player);
            
            index_player++;
            if (index_player == 4)
                index_player = 0;
            
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
            cout << "you passed level " << i + 1 << "! \n";
            cout << "ready for next level?\n" << "press enter\n";
            enter = _getch();
        }
    }
    if (!exit)
        cout << "you passed all the levels! congratulations" << endl;
    else
        cout << "you dumb shit you didnt passed the game" << endl;
    in.close();
}

//--------------------------------------------------------------
char get_player(int index)
{
    switch (index)
    {
    case king: return 'k';
    case mage: return 'm';
    case warrior: return 'w';
    case thief: return 't';
    }
}