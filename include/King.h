#pragma once
#include <conio.h>
#include "io.h"
#include "special_keys.h"
class Board;

class King {
public:
	King();
	void set_cordinate(const int row, const int col);
	int get_row() const;
	int get_col() const;
private:
	int m_row ;
	int m_col ;
};
