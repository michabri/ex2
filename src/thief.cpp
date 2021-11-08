#include "thief.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
Thief::Thief()
	:m_row(0), m_col(0), m_has_key(false)
{}
//-------------------------------------------------------------
void Thief::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------
int Thief::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------
int Thief::get_col() const
{
	return m_col;
}
//-------------------------------------------------------------
void Thief::set_has_key()
{
	m_has_key = !m_has_key;
}
//-------------------------------------------------------------
bool Thief::get_has_key() const
{
	return m_has_key;
}
