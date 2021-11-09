#include <iostream>
#include <conio.h>

#include "board.h"
#include "king.h"
#include "mage.h"
#include "warrior.h"
#include "thief.h"
#include "Teleport.h"
#include "special_keys.h"
#include "controller.h"
#include "checkValid.h"
//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;

//-------------const section-------------------

//-------------------------------------------------------------
Controller::Controller()
	:m_player_on_key{ false }, m_player_on_teleport{ false }
{}
//-------------------------------------------------------------------

//this funciton checks if the player moved, to update the board
bool Controller::move_player(Board* board, const char player, bool& victory)
{
	switch (player)
	{
	case 'k': 
		if (!move_king(board))
			return false;
		if (m_check_valid.get_victory())
			victory = true;
		return true;
	case 'm':
		if (!move_mage(board))
			return false;
		return true;
	case 'w':
		if (!move_warrior(board))
			return false;
		return true;
	case 't':
		if (!move_thief(board))
			return false;
		return true;
	}
	return false;
}

//-------------------------------------------------------------------

//this function moves the king
bool Controller::move_king(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;
	//set the kings location
	old_row = new_row = m_king.get_row();
	old_col = new_col = m_king.get_col();
	
	new_coordinate(new_row, new_col);	//checks where is the index we want to move to

	//checks if the movement is valid
	if (!m_check_valid.check_valid_king(new_row, new_col, board))
		return false;
	
	//checks if the king reached the '@'
	m_check_valid.check_win(board, new_row, new_col);
	if (m_check_valid.get_victory())
		return true;
	
	//set the new coordinate
	m_king.set_coordinate(new_row, new_col);

	if (m_player_on_key[king])	//checks if the king was on a key (F)
	{
		board->set_cell(old_row, old_col, 'F');
		m_player_on_key[king] = false;
	}//checks if the king was on the teleport (X)
	else if (m_player_on_teleport[king])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[king] = false;
	}//default set is " " (space)
	else
		board->set_cell(old_row, old_col, ' ');
	//checks if the king is on a teleport or a key
	if (board->get_cell(new_row, new_col) == 'F')
		m_player_on_key[king] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[king] = true;
		find_next_teleport(new_row, new_col);
		m_king.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 'k');
	return true;
	
}

//-------------------------------------------------------------------

//this function moves the king
bool Controller::move_mage(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;
	//set coordinates
	old_row = new_row = m_mage.get_row();
	old_col = new_col = m_mage.get_col();

	new_coordinate(new_row, new_col);
	//checks is the movement is valid
	if (!m_check_valid.check_valid_mage(new_row, new_col, board))
		return false;

	m_mage.set_coordinate(new_row, new_col);

	//checks if the player was on a key or teleport
	if (m_player_on_key[mage])
	{
		board->set_cell(old_row, old_col, 'F');
		m_player_on_key[mage] = false;
	}
	else if (m_player_on_teleport[mage])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[mage] = false;
	}
	else
		board->set_cell(old_row, old_col, ' ');

	//checks if the player is on a key or teleport
	if (board->get_cell(new_row, new_col) == 'F')
		m_player_on_key[mage] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
		m_player_on_teleport[mage] = true;
	
	board->set_cell(new_row, new_col, 'm');
	return true;
}

//-------------------------------------------------------------------

//this funciton moves the warrior
bool Controller::move_warrior(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;
	//set coordinates
	old_row = new_row = m_warrior.get_row();
	old_col = new_col = m_warrior.get_col();

	new_coordinate(new_row, new_col);
	//checks if the movement is valid
	if (!m_check_valid.check_valid_warrior(new_row, new_col, board))
		return false;
	//set the coordinates
	m_warrior.set_coordinate(new_row, new_col);

	//checks if the player was on a key or teleport
	if (m_player_on_key[warrior] )
	{
		board->set_cell(old_row, old_col, 'F');
		m_player_on_key[warrior] = false;
	}
	else if (m_player_on_teleport[warrior])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[warrior] = false;
	}
	else
		board->set_cell(old_row, old_col, ' ');

	//checks if the player is on a key or a monster(!) or a teleport
	if (board->get_cell(new_row, new_col) == 'F' || board->get_cell(new_row, new_col) == '!')
		m_player_on_key[warrior] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[warrior] = true;
		find_next_teleport(new_row, new_col);
		m_warrior.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 'w');
	return true;
}

//-------------------------------------------------------------------

//this function moves the thief
bool Controller::move_thief(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;
	//set coordinates
	old_row = new_row = m_thief.get_row();
	old_col = new_col = m_thief.get_col();

	new_coordinate(new_row, new_col);
	//checks if the kmovement is valid
	if (!m_check_valid.check_valid_thief(new_row, new_col, board, m_thief.get_has_key()))
		return false;

	m_thief.set_coordinate(new_row, new_col);
	//checks if the thief was on a teleport or a key
	if (m_player_on_key[thief] && m_thief.get_has_key())
	{
		board->set_cell(old_row, old_col, 'F');
		m_player_on_key[thief] = false;
	}
	else if (m_player_on_teleport[thief])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[thief] = false;
	}
	else
		board->set_cell(old_row, old_col, ' ');

	//if the thief took a key update the menu
	if (board->get_cell(new_row, new_col) == 'F')
	{
		if (!m_thief.get_has_key())
			m_thief.set_has_key();
		else
			m_player_on_key[thief] = true;
	}//checks if we reached a gate(#)
	else if (board->get_cell(new_row, new_col) == '#' && m_thief.get_has_key())
		m_thief.set_has_key();
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[thief] = true;
		find_next_teleport(new_row, new_col);
		m_thief.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 't');
	return true;
}

//-------------------------------------------------------------------

//this function sets the coordinates of the player
void Controller::initialize_players(const char c, const int row, const int col)
{
	switch (c)
	{
	case 'k': m_king.set_coordinate(row, col); break;
	case 'm': m_mage.set_coordinate(row, col); break;
	case 'w': m_warrior.set_coordinate(row, col); break;
	case 't': m_thief.set_coordinate(row, col); break;
	case 'X': 
		m_teleports.push_back(Teleport(row, col));
		break;
	}
}

//-------------------------------------------------------------

//this function returns the new indexes of the coordinate (according to the players movement)
void Controller::new_coordinate(int &row, int &col) const
{
	auto move = _getch();
	switch ((SpecialKeys)move)
	{
	case KB_Up: 
		row--;
		break;
	case KB_Down: 
		row++; 
		break; 
	case KB_Left: 
		col--; 
		break;
	case KB_Right: 
		col++;
		break;
	}
}
//-------------------------------------------------------------

//this function finds the teleport
void Controller::find_next_teleport(int &row, int &col) const
{
	for (int i = 0; i < m_teleports.size(); i++)
	{
		if (m_teleports[i].get_row() == row && m_teleports[i].get_col() == col)
		{
			if (i % 2 == 0)
			{
				row = m_teleports[i + 1].get_row();
				col = m_teleports[i + 1].get_col();
				break;
			}
			else
			{
				row = m_teleports[i - 1].get_row();
				col = m_teleports[i - 1].get_col();
				break;
			}
		}
	}
}
//-------------------------------------------------------------

//this function returns if the king has a key or not
bool Controller::get_has_key() const
{
	return m_thief.get_has_key();
}