#pragma once
#include "Location.h"

class Warrior {
public:
	Warrior();
	Location getLocation() const;
	void setLocation(const Location loc);
	bool checkValidMove(const char c) const;

private:
	Location m_loc;
};
