#include "checkValid.h"
#include "special_keys.h"
#include "board.h"



//---------------------------------------------------------
CheckValid::CheckValid()
	:m_victory(false)
{}
//---------------------------------------------------------
bool CheckValid::check_valid_king(const int row, const int col, const Board* board) const
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '@' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------
bool CheckValid::check_valid_mage(const int row,const int col, const Board* board) const
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '*'
			|| board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------
bool CheckValid::check_valid_warrior(const int row, const int col, const Board* board) const
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '!' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------
bool CheckValid::check_valid_thief(const int row, const int col, const Board* board, const int keys) const
{
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == 'F' ||
			board->get_cell(row, col) == 'X' ||
			(board->get_cell(row, col) == '#' && keys > 0)))
		return true;
	else
		return false;
}
//-------------------------------------------------------------
void CheckValid::check_win(const Board* board, const int row, const int col)
{
	if (board->get_cell(row, col) == '@')
		m_victory = true;
	else
		m_victory = false;
}
//-------------------------------------------------------------
bool CheckValid::get_victory() const
{
	return m_victory;
}
