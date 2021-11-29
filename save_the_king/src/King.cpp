#include "king.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//set the kings default coordinates
King::King()
	:m_loc(0,0)
{}
//-------------------------------------------------------------
//set the kings given coordinates
void King::setLocation(const Location loc)
{
	m_loc = loc;
}
//-------------------------------------------------------------
Location King::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------
bool King::checkValidMove(const char c)
{
	if (c == ' ' || c == '@' || c == 'F' || c == 'X')
		return true;
	else
		return false;
}