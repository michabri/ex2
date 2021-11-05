#pragma once
#include "special_keys.h"
#include "King.h"
#include "Controller.h"
//-------------const section-------------------
const int LENGTH = 50;

//------------class declaration-----------------
//class King;

class Board 
{
public:
	Board() = default;
	Board(const char *file_name);
	void print_board(char palyer, int counter, int key);
	void initialize_members(char c, const int row, const int col);
	bool move_player(char player, bool &victory);
	bool check_valid_player(const char player) const;
	char get_cell(int row, int col) const;
	int get_row_board() const;
	int get_col_board() const;
private:
	char m_board[LENGTH][LENGTH] ;
	int m_lenght_row;
	int m_length_col;
	King m_king;
	Controller m_controller;
};
