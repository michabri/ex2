#include "warrior.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//sets the warriors default coordinates
Warrior::Warrior()
	:m_loc(0,0)
{}
//-------------------------------------------------------------
//sets the warriors given coordinates
void Warrior::setLocation(const Location loc)
{
	m_loc = loc;
}

//-------------------------------------------------------------
Location Warrior::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------
bool Warrior::checkValidMove(const char c) const
{
	if (c == ' ' || c == '!' || c == 'F' || c == 'X')
		return true;
	else
		return false;
}