#include <iostream>
#include "Game.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

int main()
{
	Game game{};

	Player player{ &game, "Player 1" };
	game.setPlayer(&player);
	Item item{ &game, "Coins" };
	game.addItem(&item);
	Enemy enemy{ &game, "Enemy 1", true };
	game.addEnemy(&enemy);
}
