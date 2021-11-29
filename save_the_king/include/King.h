#pragma once
#include "Location.h"

class King {
public:
	King();
	Location getLocation() const;
	void setLocation(const Location loc);
	bool checkValidMove(const char c);
private:
	Location m_loc;
};
