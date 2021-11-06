#pragma once
class Board;
class King;

class Controller {
public:
	Controller();
	void check_valid_king(int row, int col, const Board* board);
	void check_valid_mage(int row, int col, const Board* board);
	void check_valid_warrior(int row, int col, const Board* board);
	void check_valid_thief(int row, int col, const Board* board);
	void move(int& row, int& col) const;
	bool get_valid_movement() const;
	bool check_win(const Board* board, const int row, const int col) const;

private:
	bool m_valid_movement;
};