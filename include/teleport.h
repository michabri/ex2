#pragma once

class Teleport {
public:
	Teleport();
	Teleport(const int row,const int col);
	void set_coordinate(const int row, const int col);
	int get_row() const;
	int get_col() const;
private:
	int m_row;
	int m_col;
};
