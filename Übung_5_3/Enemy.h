#pragma once
#include <iostream>

class Enemy : public Player
{
public:
	Enemy(Game* game, const std::string& name, bool isAttacking)
		: Player(game, name)
		, m_isAttacking{ isAttacking }
	{
	}

private:
	bool m_isAttacking;
};
