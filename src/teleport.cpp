#include "teleport.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
Teleport::Teleport()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------
Teleport::Teleport(const int row, const int col)
	:m_row(row), m_col(col)
{}

//-------------------------------------------------------------
void Teleport::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------
int Teleport::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------
int Teleport::get_col() const
{
	return m_col;
}
