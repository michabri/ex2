#include "mage.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//sets the mages dafault coordinates
Mage::Mage()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------

//sets the mages given coordinates
void Mage::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------

//returns the mages row
int Mage::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------

//returns the mages column
int Mage::get_col() const
{
	return m_col;
}
