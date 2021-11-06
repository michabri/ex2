#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <cstring>

#include "board.h"
#include "special_keys.h"
#include "controller.h"
//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

//-------------const section-------------------

Controller::Controller()
:m_valid_movement(false)
{}
//---------------------------------------------------------
void Controller::check_valid_king(int row, int col, const Board* board)
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == '_' || board->get_cell(row, col) == '@' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		m_valid_movement = true;
	else 
		m_valid_movement = false;
}

//---------------------------------------------------------
void Controller::check_valid_thief(int row, int col, const Board* board)
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == '_' || board->get_cell(row, col) == 'F' ||
			 board->get_cell(row, col) == 'X' || 
			(board->get_cell(row, col) == '#' && board->get_key_counter() > 0)))
		m_valid_movement = true;
	else
		m_valid_movement = false;
}

//---------------------------------------------------------
void Controller::check_valid_mage(int row, int col, const Board* board)
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == '_' || board->get_cell(row, col) == '*' 
		||	board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		m_valid_movement = true;
	else
		m_valid_movement = false;
}

//---------------------------------------------------------
void Controller::check_valid_warrior(int row, int col, const Board* board)
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == '_' || board->get_cell(row, col) == '!' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		m_valid_movement = true;
	else
		m_valid_movement = false;
}

//-------------------------------------------------------------
void Controller::move(int &row, int &col) const
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
		col -= 2; 
		break;
	case KB_Right: 
		col += 2;
		break;
	}
}
//-------------------------------------------------------------
bool Controller::get_valid_movement() const
{
	return m_valid_movement;
}
//-------------------------------------------------------------
bool Controller::check_win(const Board* board, const int row, const int col) const
{
	if (board->get_cell(row, col) == '@')
		return true;
	return false;
}