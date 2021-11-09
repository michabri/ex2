#include "checkValid.h"
#include "special_keys.h"
#include "board.h"


//---------------------------------------------------------

//sets victory to be false
CheckValid::CheckValid()
	:m_victory(false)
{}
//---------------------------------------------------------

//this function checks if the kings movement is valid
bool CheckValid::check_valid_king(const int row, const int col, const Board* board) const
{//king can walk on ' '(space), F(key), X(teleport) and @(victory)
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '@' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------

//this function checks if the mages movement is valid
bool CheckValid::check_valid_mage(const int row,const int col, const Board* board) const
{//mage can walk on ' '(space), *(fire), F(key), X(teleport)
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '*'
			|| board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------

//this function checks if the warriors movement is valid
bool CheckValid::check_valid_warrior(const int row, const int col, const Board* board) const
{//warrior can walk on ' '(space), !(monster), F(key), X(teleport)
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == '!' ||
			board->get_cell(row, col) == 'F' || board->get_cell(row, col) == 'X'))
		return true;
	else
		return false;
}

//---------------------------------------------------------

//this fucntion checks if the thiefs movement is valid
bool CheckValid::check_valid_thief(const int row, const int col, const Board* board, const bool has_key) const
{//thief can walk in ' '(space), F(key), X(teleport), #(gate)
	if (row < board->get_row_board() && row >= 0 &&
		col <= board->get_col_board() && col >= 0 &&
		(board->get_cell(row, col) == ' ' || board->get_cell(row, col) == 'F' ||
			board->get_cell(row, col) == 'X' ||
			(board->get_cell(row, col) == '#' && has_key)))
		return true;
	else
		return false;
}
//-------------------------------------------------------------

//this function checks if the player won the game
void CheckValid::check_win(const Board* board, const int row, const int col)
{//winning the game is by getting the K(ing) to the @(chair)
	if (board->get_cell(row, col) == '@')
		m_victory = true;
	else
		m_victory = false;
}
//-------------------------------------------------------------

//return the victory status
bool CheckValid::get_victory() const
{
	return m_victory;
}
