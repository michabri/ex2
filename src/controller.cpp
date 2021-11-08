#include <iostream>
#include <conio.h>

#include "io.h"
#include "board.h"
#include "king.h"
#include "mage.h"
#include "warrior.h"
#include "thief.h"
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
	:m_player_on_key{ false }, m_player_on_teleport{ false },
	m_key_counter(0)
{}
//-------------------------------------------------------------------
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
}

//-------------------------------------------------------------------
bool Controller::move_king(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;

	old_row = new_row = m_king.get_row();
	old_col = new_col = m_king.get_col();
	
	new_coordinate(new_row, new_col);

	if (!m_check_valid.check_valid_king(new_row, new_col, board))
		return false;
	
	m_check_valid.check_win(board, new_row, new_col);
	if (m_check_valid.get_victory())
		return true;
	
	m_king.set_coordinate(new_row, new_col);

	if (m_player_on_key[king])
	{
		board->set_cell(old_row, old_col, 'F');
		m_player_on_key[king] = false;
	}
	else if (m_player_on_teleport[king])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[king] = false;
	}
	else
		board->set_cell(old_row, old_col, ' ');

	if (board->get_cell(new_row, new_col) == 'F')
		m_player_on_key[king] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[king] = true;
		find_next_teleport(board, new_row, new_col);
		m_king.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 'k');
	return true;
	
}

//-------------------------------------------------------------------
bool Controller::move_mage(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;

	old_row = new_row = m_mage.get_row();
	old_col = new_col = m_mage.get_col();

	new_coordinate(new_row, new_col);
	if (!m_check_valid.check_valid_mage(new_row, new_col, board))
		return false;

	m_mage.set_coordinate(new_row, new_col);

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

	if (board->get_cell(new_row, new_col) == 'F')
		m_player_on_key[mage] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
		m_player_on_teleport[mage] = true;
	
	board->set_cell(new_row, new_col, 'm');
	return true;
}

//-------------------------------------------------------------------
bool Controller::move_warrior(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;

	old_row = new_row = m_warrior.get_row();
	old_col = new_col = m_warrior.get_col();

	new_coordinate(new_row, new_col);
	if (!m_check_valid.check_valid_warrior(new_row, new_col, board))
		return false;

	m_warrior.set_coordinate(new_row, new_col);

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

	if (board->get_cell(new_row, new_col) == 'F' || board->get_cell(new_row, new_col) == '!')
		m_player_on_key[warrior] = true;
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[warrior] = true;
		find_next_teleport(board, new_row, new_col);
		m_warrior.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 'w');
	return true;
}

//-------------------------------------------------------------------
bool Controller::move_thief(Board* board)
{
	int old_row = 0, new_row = 0;
	int old_col = 0, new_col = 0;

	old_row = new_row = m_thief.get_row();
	old_col = new_col = m_thief.get_col();

	new_coordinate(new_row, new_col);
	if (!m_check_valid.check_valid_thief(new_row, new_col, board, m_key_counter))
		return false;

	m_thief.set_coordinate(new_row, new_col);

	if (m_player_on_teleport[thief])
	{
		board->set_cell(old_row, old_col, 'X');
		m_player_on_teleport[thief] = false;
	}
	else
		board->set_cell(old_row, old_col, ' ');

	if (board->get_cell(new_row, new_col) == 'F')
		m_key_counter++;
	else if (board->get_cell(new_row, new_col) == '#')
		m_key_counter--;
	else if (board->get_cell(new_row, new_col) == 'X')
	{
		m_player_on_teleport[thief] = true;
		find_next_teleport(board, new_row, new_col);
		m_thief.set_coordinate(new_row, new_col);
	}

	board->set_cell(new_row, new_col, 't');
	return true;
}

//-------------------------------------------------------------------
void Controller::initialize_players(const char c, const int row, const int col)
{
	switch (c)
	{
	case 'k': m_king.set_coordinate(row, col); break;
	case 'm': m_mage.set_coordinate(row, col); break;
	case 'w': m_warrior.set_coordinate(row, col); break;
	case 't': m_thief.set_coordinate(row, col); break;
	}
}

//-------------------------------------------------------------
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
void Controller::find_next_teleport(const Board* board, int &row, int &col) const
{
	bool found_teleport = false;
	bool start = false;
	col++;
	while (!found_teleport)
	{
		if (start)
		{
			row = 0;
			col = 0;
		}
		for(; row < board->get_row_board(); row++)
		{
			for (; col < board->get_col_board(); col++)
			{
				if (board->get_cell(row, col) == 'X')
				{
					found_teleport = true;
					break;
				}
			}
			if (found_teleport)
				break;
			col = 0;
		}
		if (row == board->get_row_board())
			start = true;
	}
}
int Controller::get_key_counter() const
{
	return m_key_counter;
}