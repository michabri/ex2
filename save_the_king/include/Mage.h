#pragma once
#include "Location.h"
#include "io.h"


class Mage {
public:
	Mage();
	void setLocation(const Location loc);
	Location getLocation() const;
	bool checkValidMove(const char c) const;
private:
	Location m_loc;
};
