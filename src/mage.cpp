#include "mage.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
Mage::Mage()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------
void Mage::set_coordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------
int Mage::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------
int Mage::get_col() const
{
	return m_col;
}
