#include <iostream>
#include <cstdlib>
#include <fstream>

#include "board.h"
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
Board::Board()
	:m_length_row(0), m_length_col(0), m_board{' '}
{}
//-------------------------------------------------------------
Board::Board(const char* file_name, Controller *controller)
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
			
			controller->initialize_players(m_board[row][col], row, col);
			
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
void Board::print_board(char player, int counter, bool key)
{
	cout << "The palyer is: " << player << endl;
	cout << "The amount of steps: " << counter << endl;
	if (key)
		cout << "The thief has a key" << endl;
	else
		cout << "The thief doesnt have a key" << endl;
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
char Board::get_cell(int row, int col) const
{
	return m_board[row][col];
}
//-------------------------------------------------------------------
void Board::set_cell(const int row, const int col, const char c) 
{
	m_board[row][col] = c;
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

