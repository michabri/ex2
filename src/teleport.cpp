#include "teleport.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//set teleports default coordinates
Teleport::Teleport()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------

//create a teleport with the required coordinates
Teleport::Teleport(const int row, const int col)
	:m_row(row), m_col(col)
{}

//-------------------------------------------------------------

//set the teleports coordinates
void Teleport::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------

//get the teleports row
int Teleport::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------

//get the teleports column
int Teleport::get_col() const
{
	return m_col;
}
