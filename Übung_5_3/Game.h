#pragma once
#include <iostream>

// Vorausdeklaration
class Player;
class Enemy;
class Item;

class Game
{
public:
	Game()
		: m_player{ nullptr }
		, m_enemies{}
		, m_items{}
	{
	}

	void setPlayer(Player* player)
	{
		m_player = player;
	}

	void addEnemy(Enemy* enemy)
	{
		const size_t enemyCapacity{ sizeof(m_enemies) / sizeof(m_enemies[0]) };
		for (size_t i = 0; i < enemyCapacity; ++i)
		{
			if (m_enemies[i] == nullptr)
			{
				m_enemies[i] = enemy;
				break;
			}
		}
	}

	void addItem(Item* item)
	{
		const size_t itemCapacity{ sizeof(m_items) / sizeof(m_items[0]) };
		for (size_t i = 0; i < itemCapacity; ++i)
		{
			if (m_items[i] == nullptr)
			{
				m_items[i] = item;
				break;
			}
		}
	}

private:
	Player* m_player;
	Enemy* m_enemies[10];
	Item* m_items[10];
};
