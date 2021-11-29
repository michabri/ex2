#pragma once
#include <string>
#include <vector>
#include "io.h"

using std::vector;
using std::string;

//-------------const section-------------------

//------------class declaration-----------------

class Board 
{
public:
	Board();
	void setBoard(std::string file_level);
	void printBoard(char player, int counter, bool key);
	char getCell(const Location loc) const;
	void setCell(const Location loc, const char c);
	int getRowBoard() const;
	int getColBoard() const;
	void initialzieTeleports(const int i, string line);
	void findNextTeleport(Location& loc) const;
	bool checkOutOfBoard(Location loc) const;
	void clearBoard();

private:
	vector<string> m_board;
	vector <Location> m_teleports;
	int m_row_length;
	int m_col_length;
};
