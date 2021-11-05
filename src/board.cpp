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
		m_length_col = col - 1;
		col = 0;

	} while (!(in.eof()) && row < LENGTH);
	
	if (row == LENGTH)
	{
		cerr << "The board is too big" << endl;
		exit(EXIT_FAILURE);
	}
	m_board[row][col] = '\0';

	m_lenght_row = row ;
	
}
//--------------------------------------------------------------
void Board::print_board(char player, int counter, int key)
{
	cout << "The palyer is: " << player << endl;
	cout << "The amount of steps: " << counter << endl;
	cout << "The thief has: " << key << " keys" << endl;
	cout << endl;
	for (int row = 0; row < m_lenght_row; row++)
	{
		for (int col = 0; m_board[row][col]!='\0'; col++)
		{
			cout << m_board[row][col];
		}
		cout << endl;
	}
}
//-------------------------------------------------------------------
void Board::initialize_members(char c,const int row, const int col)
{
	switch (c)
	{
	case 'k': m_king.set_cordinate(row, col); 
		break;
	
	}
}
//-------------------------------------------------------------------
bool Board::move_player(char player, bool &victory)
{
	int row = 0, col = 0, old_row = 0, old_col = 0;
	switch (player)
	{
	case 'k':
		
		old_row = row = m_king.get_row(); 
		old_col = col = m_king.get_col();
		
		m_controller.move(row, col);
		m_controller.check_valid_king(row, col, this);
		
		if (!m_controller.get_valid_movement())
			return false;
		
		if (m_controller.check_win(this, row, col))
			victory = true;
		m_king.set_cordinate(row, col);
		m_board[old_row][old_col] = '_';
		m_board[m_king.get_row()][m_king.get_col()] = 'k';
		return true;
	}
}
//-------------------------------------------------------------------
bool Board::check_valid_player(const char player) const
{
	if (player == 'k' || player == 'm' || player == 't' || player == 'w')
		return true;
	return false;
}
//-------------------------------------------------------------------
char Board::get_cell(int row, int col) const
{
	return m_board[row][col];
}
//-------------------------------------------------------------------
int Board::get_row_board() const
{
	return m_lenght_row;
}
//-------------------------------------------------------------------
int Board::get_col_board() const
{
	return m_length_col;
}