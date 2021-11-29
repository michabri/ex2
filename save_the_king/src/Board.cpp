#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"
#include "SpecialKeys.h"


//-------------using section-------------------
using std::cerr;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::getline;
//-------------const section-------------------

//-------------------------------------------------------------
Board::Board()
	:m_row_length(0), m_col_length(0)
{}
//-------------------------------------------------------------
void Board::setBoard(std::string file_level)
{
	ifstream in;
	in.open(file_level);	//open the file
	if (!in.is_open())
	{
		cerr <<"could not open the file -" << file_level << endl;
		exit(EXIT_FAILURE);
	}
	string line;
	int i=0;
	while (getline(in, line)) 
	{
		m_board.push_back(line);
		initialzieTeleports(i, line);
		m_col_length = line.size();
		i++;
	}
	m_row_length = i;
	in.close();
}
//--------------------------------------------------------------

//this function prints the board
void Board::printBoard(char player, int counter, bool key)
{
	cout << "The palyer is: " << player << endl;
	cout << "The amount of steps: " << counter << endl;
	if (key)
		cout << "The thief has a key" << endl;
	else
		cout << "The thief doesnt have a key" << endl;
	cout << endl;
	for (int row = 0; row < m_board.size(); row++)
	{
		cout << m_board[row];
		cout << endl;
	}
}

//-------------------------------------------------------------------

//this function returns the current cell (char)
char Board::getCell(const Location loc) const
{
	return m_board[loc.row][loc.col];
}
//-------------------------------------------------------------------

//this function sets the cells coordinates
void Board::setCell(const Location loc, const char c) 
{
	m_board[loc.row][loc.col] = c;
}

//-------------------------------------------------------------------

//this function returns the row
int Board::getRowBoard() const
{
	return m_row_length;
}
//-------------------------------------------------------------------
//this function returns the column
int Board::getColBoard() const
{
	return m_col_length;
}
//-------------------------------------------------------------------
bool Board::checkOutOfBoard(Location loc) const
{
	if (loc.row < m_row_length && loc.row >= 0 &&
		loc.col < m_col_length && loc.col >= 0)
		return false;
	else
		return true;
}
//-------------------------------------------------------------------
void Board::clearBoard()
{
	int size = m_board.size();
	for (int i = 0; i < size; i++)
	{
		m_board[i].clear();
	}
	m_board.clear();
	m_row_length = 0;
	m_col_length = 0;
}
//-------------------------------------------------------------------
void Board::initialzieTeleports(const int row, string line)
{
	for (int col = 0;  col < line.size(); col++)
	{
		if (line[col] == 'X')
			m_teleports.push_back(Location(row, col));
	}
}
//-------------------------------------------------------------------
void Board::findNextTeleport(Location& loc) const
{
	for (int i = 0; i < m_teleports.size(); i++)
	{
		if (m_teleports[i].row == loc.row && m_teleports[i].col == loc.col)
		{
			if (i % 2 == 0)
			{
				loc = m_teleports[i + 1];
				break;
			}
			else
			{
				loc = m_teleports[i - 1];
				break;
			}
		}
	}
}
