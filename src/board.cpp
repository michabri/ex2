#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <conio.h>

#include "board.h"
#include "io.h"
#include "special_keys.h"


//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

//-------------const section-------------------

//-------------------------------------------------------------
//-------------------------------------------------------------
Board::Board(const char* file_name)
	:m_player_on_key{ false }, m_player_on_teleport{ false }, 
	m_key_counter(0), m_length_row(0), m_length_col(0)
{
	
	ifstream in;
	in.open(file_name);
	if (!in.is_open())
	{
		cerr <<"could not open the file -" << file_name  << endl;
		exit(EXIT_FAILURE);
	}
	
	int row = 0, col = 0;
	
	do {
		col = 0;
		do {
			m_board[row][col] = in.get();
			if(in.fail())
			{
				in.get();
				break;
			}
			
			initialize_members(m_board[row][col], row, col);
			
			col++;
		} 
		while (m_board[row][col - 1] != '\n' &&
			m_board[row][col - 1] != '\0' &&
			col < LENGTH);
		
		if (col == LENGTH)
		{
			cerr << "The board is too big" << endl;
			exit(EXIT_FAILURE);
		}
		
		m_board[row][col] = '\0';
		row++;

	} while (!(in.eof()) && row < LENGTH);
	
	if (row == LENGTH)
	{
		cerr << "The board is too big" << endl;
		exit(EXIT_FAILURE);
	}
	m_board[row][col] = '\0';

	m_length_col = col+1;
	m_length_row = row ;
	in.close();
}
//--------------------------------------------------------------
void Board::print_board(char player, int counter, int key)
{
	cout << "The palyer is: " << player << endl;
	cout << "The amount of steps: " << counter << endl;
	cout << "The thief has: " << key << " keys" << endl;
	cout << endl;
	for (int row = 0; row < m_length_row; row++)
	{
		for (int col = 0; m_board[row][col]!='\0'; col++)
		{
			cout << m_board[row][col];
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------
void Board::initialize_members(char c, const int row, const int col)
{
	switch (c)
	{
	case 'k': m_king.set_coordinate(row, col); break;
	case 'm': m_mage.set_coordinate(row, col); break;
	case 'w': m_warrior.set_coordinate(row, col); break;
	case 't': m_thief.set_coordinate(row, col); break;	
	}
}
//-------------------------------------------------------------------
bool Board::move_player(char player, bool &victory)
{
	int new_row = 0, new_col = 0, 
		old_row = 0, old_col = 0;
	switch (player)
	{
	case 'k':
		
		old_row = new_row = m_king.get_row(); 
		old_col = new_col = m_king.get_col();
		
		m_controller.move(new_row, new_col);
		m_controller.check_valid_king(new_row, new_col, this);
		
		if (!m_controller.get_valid_movement())
			return false;
		
		if (m_controller.check_win(this, new_row, new_col))
		{
			victory = true;
			return true;
		}
		
		m_king.set_coordinate(new_row, new_col);
		
		if (m_player_on_key[king])
		{
			m_board[old_row][old_col] = 'F';
			m_player_on_key[king] = false;
		}
		else if (m_player_on_teleport[king])
		{
			m_board[old_row][old_col] = 'X';
			m_player_on_teleport[king] = false;
		}
		else
			m_board[old_row][old_col] = ' ';

		if (m_board[new_row][new_col] == 'F')
			m_player_on_key[king] = true;
		else if (m_board[new_row][new_col] == 'X')
		{
			m_player_on_teleport[king] = true;
			m_controller.find_next_teleport(this, new_row, new_col);
			m_king.set_coordinate(new_row, new_col);
		}
		
		m_board[new_row][new_col] = 'k';
		return true;
	
	case 'm':
		old_row = new_row = m_mage.get_row();
		old_col = new_col = m_mage.get_col();

		m_controller.move(new_row, new_col);
		m_controller.check_valid_mage(new_row, new_col, this);

		if (!m_controller.get_valid_movement())
			return false;
		
		m_mage.set_coordinate(new_row, new_col);
		
		if (m_player_on_key[mage])
		{
			m_board[old_row][old_col] = 'F';
			m_player_on_key[mage] = false;
		}
		else if (m_player_on_teleport[mage])
		{
			m_board[old_row][old_col] = 'X';
			m_player_on_teleport[mage] = false;
		}
		else
			m_board[old_row][old_col] = ' ';

		if (m_board[new_row][new_col] == 'F')
			m_player_on_key[mage] = true;
		else if (m_board[new_row][new_col] == 'X')
			m_player_on_teleport[mage] = true;

		m_board[new_row][new_col] = 'm';
		return true;
	
	case 'w':
		old_row = new_row = m_warrior.get_row();
		old_col = new_col = m_warrior.get_col();

		m_controller.move(new_row, new_col);
		m_controller.check_valid_warrior(new_row, new_col, this);

		if (!m_controller.get_valid_movement())
			return false;

		m_warrior.set_coordinate(new_row, new_col);
		
		if (m_player_on_key[warrior])
		{
			m_board[old_row][old_col] = 'F';
			m_player_on_key[warrior] = false;
		}
		else if (m_player_on_teleport[warrior])
		{
			m_board[old_row][old_col] = 'X';
			m_player_on_teleport[warrior] = false;
		}
		else
			m_board[old_row][old_col] = ' ';

		if (m_board[new_row][new_col] == 'F' || m_board[new_row][new_col] == '!')
			m_player_on_key[warrior] = true;
		else if (m_board[new_row][new_col] == 'X')
		{
			m_player_on_teleport[warrior] = true;
			m_controller.find_next_teleport(this, new_row, new_col);
			m_warrior.set_coordinate(new_row, new_col);
		}
		m_board[new_row][new_col] = 'w';
		return true;

	case 't':
		old_row = new_row = m_thief.get_row();
		old_col = new_col = m_thief.get_col();

		m_controller.move(new_row, new_col);
		m_controller.check_valid_thief(new_row, new_col, this);

		if (!m_controller.get_valid_movement())
			return false;

		m_thief.set_coordinate(new_row, new_col);

		if (m_player_on_teleport[thief])
		{
			m_board[old_row][old_col] = 'X';
			m_player_on_teleport[thief] = false;
		}
		else
			m_board[old_row][old_col] = ' ';

		
		if (m_board[new_row][new_col] == 'F')
			inc_key_counter();
		else if (m_board[new_row][new_col] == '#' && get_key_counter() > 0)
			dec_key_counter();
		else if (m_board[new_row][new_col] == 'X')
		{
			m_player_on_teleport[thief] = true;
			m_controller.find_next_teleport(this, new_row, new_col);
			m_thief.set_coordinate(new_row, new_col);
		}
		m_board[new_row][new_col] = 't';
		return true;
	}
	
}

//-------------------------------------------------------------------
char Board::get_cell(int row, int col) const
{
	return m_board[row][col];
}
//-------------------------------------------------------------------
int Board::get_row_board() const
{
	return m_length_row;
}
//-------------------------------------------------------------------
int Board::get_col_board() const
{
	return m_length_col;
}

//-------------------------------------------------------------------
void Board::inc_key_counter()
{
	m_key_counter++;
}

//-------------------------------------------------------------------
void Board::dec_key_counter()
{
	m_key_counter--;
}

//-------------------------------------------------------------------
int Board::get_key_counter() const
{
	return m_key_counter;
}

//-------------------------------------------------------------------
void Board::print_victory() const
{
	cout << "*       * ***** ***** ***** ***** ***** *   * " << endl;
	cout << " *     *    *   *       *   *   * *   *  * *"  << endl;
	cout << "  *   *     *   *       *   *   * *****   *" << endl;
	cout << "   * *      *   *       *   *   * * *     *" << endl;
	cout << "    *     ***** *****   *   ***** *   *   *" << endl;
}