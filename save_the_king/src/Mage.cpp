#include "mage.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//sets the mages dafault coordinates
Mage::Mage()
	:m_loc(0,0)
{}
//-------------------------------------------------------------

//sets the mages given coordinates
void Mage::setLocation(const Location loc)
{
	m_loc = loc;
}
//-------------------------------------------------------------

Location Mage::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------
bool Mage::checkValidMove(const char c) const
{
	if (c == ' ' || c == '*' || c == 'F' || c == 'X')
		return true;
	else
		return false;
}