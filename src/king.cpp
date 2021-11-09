#include "king.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//set the kings default coordinates
King::King()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------

//set the kings given coordinates
void King::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;	
}
//-------------------------------------------------------------

//get the kings row
int King::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------

//get the kings column
int King::get_col() const
{
	return m_col;
}
