#include <iostream>
#include <cstdlib> // for std::system()
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <conio.h>

#include "board.h"
#include "controller.h"
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
    char levels_names[LENGTH]; //the name of the file that contains the names of the levels
    char level_file[LENGTH];   //the name of the file level
    
    cin >> levels_names;

    ifstream in;
    in.open(levels_names);
    if (!in.is_open())  //open the files
    {
        cerr << "could not open the file -" << levels_names << endl;
        exit(EXIT_FAILURE);
    }

    Controller controller; // the class that moves the players
    char player , enter;   // player(king, mage, warrior or thief), enter key for moving to the next round
    int counter_moves = 0;       
    bool victory = false;
    auto exit = false;

    //read the name of the level
    for (int i = 0;  !exit && !in.eof(); i++)
    {
        in.getline(level_file, LENGTH);

        Board board(level_file, &controller);   //create a board according to the level
        victory = false;
        int index_player = 0;
        
        //as long as the player didnt win\exit the game
        while (!victory && !exit)
        {
            player = get_player(index_player);
            
            index_player++;
            if (index_player == 4)
                index_player = 0;
            
            std::system("cls");
            //print the current player, how many moves were made, and if the thief has a key
            board.print_board(player, counter_moves, controller.get_has_key());

            auto input = _getch();
            
            std::system("cls");

            while (input != 'p' && !exit && !victory)
            {//move the player according to the users input
                switch (input)
                {
                case SpecialKey:
                    if (controller.move_player(&board, player, victory))
                        counter_moves++;
                    break;
                default:
                    exit = handleRegularKey(input);
                }
                if (!victory)
                {
                    board.print_board(player, counter_moves, controller.get_has_key());
                    input = _getch();
                    
                    std::system("cls");
                }
            }
        }
        if (victory)
        {   //print VICTORY if the player finished the level
            print_congratulations();
            cout << "you passed level " << i + 1 << "! \n";
            cout << "ready for next level?\n" << "press enter\n";
            enter =(char) _getch();
        }
    }
    std::system("cls");
    if (!exit)
    {
        print_victory();
        cout << "you passed all the levels! congratulations" << endl;
    }
    else
        cout << "you loser didnt pass the game" << endl;
    in.close();
}

//-------------------------------------------------------------------

//return the player
char get_player(int index)
{
    switch (index)
    {
    case king: return 'k';
    case mage: return 'm';
    case warrior: return 'w';
    case thief: return 't';
    }
    return ' ';
}
//-------------------------------------------------------------------

//print the CONGRATULATIONS announcement
void print_congratulations()
{
    cout << "***** ***** *    * ***** ***** ***** ***** *   * *     ***** ***** ***** ***** *   * *****" << endl;
    cout << "*     *   * **   * *     *   * *   *   *   *   * *     *   *   *     *   *   * **  * *" << endl;
    cout << "*     *   * * *  * ***** ***** *****   *   *   * *     *****   *     *   *   * * * * *****" << endl;
    cout << "*     *   * *   ** *   * * *   *   *   *   *   * *     *   *   *     *   *   * *  **     *" << endl;
    cout << "***** ***** *    * ***** *   * *   *   *   ***** ***** *   *   *   ***** ***** *   * *****" << endl;
}
//-------------------------------------------------------------------

//print the VICTORY announcement
void print_victory()
{
    cout << "*       * ***** ***** ***** ***** ***** *   * " << endl;
    cout << " *     *    *   *       *   *   * *   *  * *" << endl;
    cout << "  *   *     *   *       *   *   * *****   *" << endl;
    cout << "   * *      *   *       *   *   * * *     *" << endl;
    cout << "    *     ***** *****   *   ***** *   *   *" << endl;
}