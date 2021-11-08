#pragma once
#include "checkValid.h"

class Board;
class King;
class Mage;
class Warrior;
class Thief;
class CheckValid;

class Controller {
public:
	Controller();
	void initialize_players(const char c, const int row, const int col);
	void new_coordinate(int& row, int& col) const;
	bool move_player(Board* board, const char player, bool& victory);
	bool move_king(Board* board);
	bool move_mage(Board* board);
	bool move_warrior(Board* board);
	bool move_thief(Board* board);
	void find_next_teleport(const Board* board, int &row, int &col) const;
	bool get_has_key() const;
private:
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Thief m_thief;
	CheckValid m_check_valid;

	bool m_player_on_key[4]; // 0 - king, 1 - mage, 2 - warrior, 3 - thief
	bool m_player_on_teleport[4];
};