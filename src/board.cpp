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
	in.open(file_name);	//open the file
	if (!in.is_open())
	{
		cerr <<"could not open the file -" << file_name  << endl;
		exit(EXIT_FAILURE);
	}
	
	int row = 0, col = 0;
	//read the map from the .txt file
	do {
		col = 0;
		do {
			m_board[row][col] = in.get();
			if(in.fail())
			{
				in.get();
				break;
			}
			//initialize the players
			controller->initialize_players(m_board[row][col], row, col);
			
			col++;
		} 
		while (m_board[row][col - 1] != '\n' &&
			m_board[row][col - 1] != '\0' &&
			col < LENGTH);
		//checks if the board is too big
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

//this function prints the board
void Board::print_board(char player, int counter, bool key)
{//prints the current player, the steps, and if the thief has a key
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

//this function returns the current cell (char)
char Board::get_cell(int row, int col) const
{
	return m_board[row][col];
}
//-------------------------------------------------------------------

//this function sets the cells coordinates
void Board::set_cell(const int row, const int col, const char c) 
{
	m_board[row][col] = c;
}

//-------------------------------------------------------------------

//this function returns the row
int Board::get_row_board() const
{
	return m_length_row;
}
//-------------------------------------------------------------------

//this function returns the column
int Board::get_col_board() const
{
	return m_length_col;
}

