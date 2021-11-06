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
	Board() = default;
	Board(const char *file_name);
	void print_board(char palyer, int counter, int key);
	void initialize_members(char c, const int row, const int col);
	bool move_player(char player, bool &victory);
	bool check_valid_player(const char player) const;
	char get_cell(int row, int col) const;
	int get_row_board() const;
	int get_col_board() const;
	void inc_key_counter();
	void dec_key_counter();
	int get_key_counter() const;
	void print_victory() const;
private:
	char m_board[LENGTH][LENGTH] ;
	int m_length_row;
	int m_length_col;
	int m_key_counter;
	bool m_player_on_key[4]; // 0 - king, 1 - mage, 2 - warrior, 3 - thief
	bool m_player_on_teleport[4];
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Thief m_thief;
	Controller m_controller;
};
