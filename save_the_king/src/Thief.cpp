#include "thief.h"

//-------------using section-------------------

//-------------const section-------------------

//-------------------------------------------------------------

//set the thiefs default coordinates
Thief::Thief()
	:m_loc(0,0), m_has_key(false)
{}
//-------------------------------------------------------------

//sets the thiefs given coordinates
void Thief::setLocation(const Location loc)
{
	m_loc = loc;
}
//-------------------------------------------------------------
Location Thief::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------
//set if the thief has a key or not
void Thief::setKey()
{
	m_has_key = !m_has_key;
}
//-------------------------------------------------------------
//returns if the player has a key or not
bool Thief::getHasKey() const
{
	return m_has_key;
}
//-------------------------------------------------------------
bool Thief::checkValidMove(const char c)
{
	if (c == ' ' || c == 'F' || c == 'X' || (c == '#' && m_has_key))
	{
		if ((c == '#' && m_has_key))
			m_has_key = false;
		return true;
	}
	else
		return false;
}
