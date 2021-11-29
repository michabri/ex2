#pragma once
#include "Location.h"

class Thief {
public:
	Thief();
	Location getLocation() const;
	void setLocation(const Location loc);
	void setKey();
	bool getHasKey() const;
	bool checkValidMove(const char c);
private:
	Location m_loc;
	bool m_has_key;
};

