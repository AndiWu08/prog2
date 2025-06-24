#pragma once
#include <iostream>

// Vorausdeklaration
class Game;

class Item
{
public:
	Item(Game* game, const std::string& name)
		: m_game{ game }
		, m_name { name	}
	{
	}

private:
	Game* m_game;
	std::string m_name;
};
