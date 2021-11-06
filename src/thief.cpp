#include "thief.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
Thief::Thief()
	:m_row(0), m_col(0)
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
