#pragma once

class Thief {
public:
	Thief();
	void set_coordinate(const int row, const int col);
	int get_row() const;
	int get_col() const;
private:
	int m_row;
	int m_col;
};

