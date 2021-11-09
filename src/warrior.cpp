#include "warrior.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//sets the warriors default coordinates
Warrior::Warrior()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------

//sets the warriors given coordinates
void Warrior::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------

//returns the warriors row
int Warrior::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------

//returns the warriors column
int Warrior::get_col() const
{
	return m_col;
}
