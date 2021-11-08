#pragma once
#include "special_keys.h"
#include "King.h"
#include "mage.h"
#include "warrior.h"
#include "thief.h"
#include "Controller.h"
//-------------const section-------------------
const int LENGTH = 50;

//------------class declaration-----------------

class Board 
{
public:
	Board();
	Board(const char *file_name, Controller *controler);
	void print_board(char player, int counter, bool key);
	char get_cell(int row, int col) const;
	void set_cell(const int row, const int col, const char c);
	int get_row_board() const;
	int get_col_board() const;
	

private:
	char m_board[LENGTH][LENGTH] ;
	int m_length_row;
	int m_length_col;
};
