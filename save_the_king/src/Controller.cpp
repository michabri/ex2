#include <iostream>
#include <conio.h>
#include <fstream>
#include "Location.h"
#include "board.h"
#include "king.h"
#include "mage.h"
#include "warrior.h"
#include "thief.h"
#include "SpecialKeys.h"
#include "controller.h"
//-------------using section-------------------
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::cin;

//-------------const section-------------------

//-------------------------------------------------------------
Controller::Controller()
{
    for (int i = 0; i < CHARACTERS; i++)
    {
        m_player_on_key[i] = false;
        m_player_on_teleport[i] = false;
    }
}

//-------------------------------------------------------------
void Controller::game()
{
    auto level_names = std::string(); //the name of the file that contains the names of the levels
    auto level_file = std::string(); //the name of the file level
    level_names = "levels.txt";
    
    ifstream in;
    in.open(level_names);
    if (!in.is_open())  //open the files
    {
        cerr << "could not open the file -" << level_names << endl;
        exit(EXIT_FAILURE);
    }

    char character, enter;   // player(king, mage, warrior or thief), enter key for moving to the next round
    auto exit = false;
    for (int i = 0; !exit && getline(in, level_file); i++) //reads from file
    {
        m_board.setBoard(level_file);
        initializeLocationCharacters();
        bool victory_level = false;
        int index_player = 0;
        int counter_moves = 0;

        while (!victory_level && !exit)
        {
            character = characterPlaying(index_player);
            index_player++;
            if (index_player == 4)
                index_player = 0;
                  
            std::system("cls");
            m_board.printBoard(character, counter_moves, m_thief.getHasKey());
            auto input = _getch();
            std::system("cls");

            while (input != 'p' && !exit && !victory_level)
            {
                switch (input)
                {
                case SpecialKey:
                    if (doesTheCharacterMoved(character, victory_level))
                        counter_moves++;
                    break;
                default:
                    exit = handleRegularKey(input);
                }
                if (!victory_level)
                {
                    m_board.printBoard(character, counter_moves, m_thief.getHasKey());
                    input = _getch();
                    std::system("cls");
                }
            }
        }
        if (victory_level)
        {   
            cout << "you passed level " << i + 1 << "! \n";
            cout << "ready for next level?\n" << "press enter\n";
            enter = (char)_getch();
            m_board.clearBoard();
            if (m_thief.getHasKey())
                m_thief.setKey();
            for (int i = 0; i < CHARACTERS; i++)
            {
                m_player_on_key[i] = false;
                m_player_on_teleport[i] = false;
            }
        }
    }
    std::system("cls");
    if (!exit)
        cout << "you passed all the levels! congratulations" << endl;
    else
        cout << "you loser, you didnt pass the game" << endl;
}
//-------------------------------------------------------------
void Controller::initializeLocationCharacters()
{
    for (int i = 0; i < m_board.getRowBoard(); i++)
    {
        for (int j = 0; j < m_board.getColBoard(); j++)
        {
            char c = m_board.getCell(Location(i, j));
            switch (c)
            {
            case 'k': m_king.setLocation(Location(i, j)); break;
            case 'm': m_mage.setLocation(Location(i, j)); break;
            case 'w': m_warrior.setLocation(Location(i, j)); break;
            case 't': m_thief.setLocation(Location(i, j)); break;
            }
        }
    }
    
}
//-------------------------------------------------------------------
//return the player
char Controller::characterPlaying(int index) const
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
bool Controller::doesTheCharacterMoved(const char character, bool& victory)
{
    Location new_loc(0,0), old_loc(0,0);
    switch (character) //gets the old location
    {
    case 'k':old_loc = new_loc = m_king.getLocation(); break;
    case 'm': old_loc = new_loc = m_mage.getLocation(); break;
    case 'w': old_loc = new_loc = m_warrior.getLocation(); break;
    case 't': old_loc = new_loc = m_thief.getLocation(); break;
    }
    newLocation(new_loc);
    if (m_board.checkOutOfBoard(new_loc))
        return false;
    
    switch (character)
    {
    case 'k':
        if(!m_king.checkValidMove(m_board.getCell(new_loc)))
            return false;
        if (isVictory(new_loc))
            victory = true;
        break;
    case 'm':
        if (!m_mage.checkValidMove(m_board.getCell(new_loc)))
            return false;
        break;
    case 'w': 
        if (!m_warrior.checkValidMove(m_board.getCell(new_loc)))
            return false;
        break;
    case 't':
        if (!m_thief.checkValidMove(m_board.getCell(new_loc)))
            return false;
        break;
    }
   
    moveCharacter(character, old_loc, new_loc);
    return true;
}
//-------------------------------------------------------------
void Controller::newLocation(Location &loc) const
{
    auto move = _getch();
    switch ((SpecialKeys)move)
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
    }
}
//-------------------------------------------------------------
bool Controller::isVictory(const Location loc) const
{
    if (m_board.getCell(loc) == '@')
        return true;
    else
        return false;
}
//-------------------------------------------------------------
void Controller::moveCharacter(const char character, const Location old_loc, Location new_loc)
{
    int index_character = 0;
    switch (character)
    {
    case 'k': index_character = 0; break;
    case 'm': index_character = 1; break;
    case 'w': index_character = 2; break;
    case 't': index_character = 3; break;
    }
    // deals with old location
    if (m_player_on_key[index_character])	//checks if the character stood on a key (F)
    {
        m_board.setCell(old_loc, 'F');
        m_player_on_key[index_character] = false;
    }
    else if (m_player_on_teleport[index_character]) //checks if the character stood on a teleport (X)
    {
        m_board.setCell(old_loc, 'X');
        m_player_on_teleport[index_character] = false;
    }
    else 
        m_board.setCell(old_loc, ' ');
    
    // deals with new Location
    if (m_board.getCell(new_loc) == 'F' || 
       ((character == 'w') && m_board.getCell(new_loc) == '!'))
    {
        if (character != 't' || (character == 't' && m_thief.getHasKey()))
            m_player_on_key[index_character] = true;
        if (character == 't' && !m_thief.getHasKey())
            m_thief.setKey();
    }
    else if (m_board.getCell(new_loc) == 'X')
    {
        m_player_on_teleport[index_character] = true;
        if(character != 'm')
            m_board.findNextTeleport(new_loc);
    }
    // sets the character in a new location on the board
    switch (character)
    {
    case 'k': m_king.setLocation(new_loc); break;
    case 'm': m_mage.setLocation(new_loc); break;
    case 'w': m_warrior.setLocation(new_loc);break;
    case 't': m_thief.setLocation(new_loc); break;
    }
    m_board.setCell(new_loc, character); 
}
