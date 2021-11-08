#pragma once
class Board;

class CheckValid {
public:
	CheckValid();
	bool check_valid_king(const int row, const int col, const Board* board) const;
	bool check_valid_mage(const int row, const int col, const Board* board) const;
	bool check_valid_warrior(const int row, const int col, const Board* board) const;
	bool check_valid_thief(const int row, const int col, const Board* board, const bool has_key) const;
	void check_win(const Board* board, const int row, const int col);
	bool get_victory() const;
private:
	bool m_victory;
};