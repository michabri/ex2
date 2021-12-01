#include "BoardSfml.h"
#include <vector>

using std::vector;

const int START_ROW = 150;
const int START_COL = 100;
//-------------------------------------------------
BoardSfml::BoardSfml(const int row, const int col)
	:m_row(row), m_col(col), m_index(0)
{}
//-------------------------------------------------
void BoardSfml::setBoard()
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			sf::Vector2f location(LEN_CELL * col + START_COL, LEN_CELL * row + START_ROW);
			Cell cell(" ", location, sf::Color::White);
			m_board.push_back(cell);
		}
	}
}
//-------------------------------------------------
void BoardSfml::setRow(const int row)
{
	m_row = row;
}
//-------------------------------------------------
void BoardSfml::setCol(const int col)
{
	m_col = col;
}
//-------------------------------------------------
void BoardSfml::draw(sf::RenderWindow& window) const 
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			int index = row * m_row + col ;
			m_board[index].draw(window);
		}
	}
}
//------------------------------------------------------------------
bool BoardSfml::handleClick(const sf::Vector2f& location)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			int index = row * m_row + col;
			if (m_board[index].handleClick(location))
			{
				m_index = index;
				return true;
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------
void BoardSfml::setTextInCell(const string text)
{
	m_board[m_index].setText(text);
}