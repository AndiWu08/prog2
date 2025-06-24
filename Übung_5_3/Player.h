#pragma once
#include <iostream>

// Vorausdeklaration
class Game;

class Player
{
public:
	Player(Game* game, const std::string& name)
		: m_game{ game }
		, m_name{ name }
	{
	}

private:
	Game* m_game;
	std::string m_name;
};
