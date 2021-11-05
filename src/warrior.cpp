#include "warrior.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------
Warrior::Warrior()
	:m_row(0), m_col(0)
{}
//-------------------------------------------------------------
void Warrior::set_cordinate(const int row, const int col)
{
	m_row = row;
	m_col = col;
}
//-------------------------------------------------------------
int Warrior::get_row() const
{
	return m_row;
}
//-------------------------------------------------------------
int Warrior::get_col() const
{
	return m_col;
}
