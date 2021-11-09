#include "thief.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//set the thiefs default coordinates
Thief::Thief()
	:m_row(0), m_col(0), m_has_key(false)
{}
//-------------------------------------------------------------

//sets the thiefs given coordinates
void Thief::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------

//returns the thiefs row
int Thief::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------

//returns the thiefs column
int Thief::get_col() const
{
	return m_col;
}
//-------------------------------------------------------------

//set if the thief has a key or not
void Thief::set_has_key()
{
	m_has_key = !m_has_key;
}
//-------------------------------------------------------------

//returns if the player has a key or not
bool Thief::get_has_key() const
{
	return m_has_key;
}
