#pragma once

class Thief {
public:
	Thief();
	void set_coordinate(const int row, const int col);
	int get_row() const;
	int get_col() const;
	void set_has_key();
	bool get_has_key() const;
private:
	int m_row;
	int m_col;
	bool m_has_key;
};

