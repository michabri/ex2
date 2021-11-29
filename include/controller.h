#pragma once
#include <vector>
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

const int CHARACTERS = 4;

class Controller {
public:
	Controller();
	void game();
	
	void initializeLocationCharacters();
	bool doesTheCharacterMoved(const char player, bool& victory);
	void newLocation(Location& loc) const;
	char characterPlaying(int index) const;
	bool isVictory(const Location loc) const;
	void moveCharacter(const char character, const Location old_loc, Location new_loc);
private:
	Board m_board;
	King m_king;
	Mage m_mage;
	Warrior m_warrior;
	Thief m_thief;

	bool m_player_on_key[CHARACTERS]; // 0 - king, 1 - mage, 2 - warrior, 3 - thief
	bool m_player_on_teleport[CHARACTERS];
};