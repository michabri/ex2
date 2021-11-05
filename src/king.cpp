#include "king.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
King::King()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------
void King::set_cordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;	
}
//-------------------------------------------------------------
int King::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------
int King::get_col() const
{
	return m_col;
}
