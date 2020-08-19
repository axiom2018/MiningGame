#include "Bomb.h"
#include "Player.h"
#include <iostream>
#include <conio.h>

bool Bomb::Execute(Player& pPlayer) 
{
	// Display message.
	std::cout << "You hit a bomb\n";

	// Do a random portion of damage within this range.
	pPlayer.Damage(10 + (rand() % 30));

	(void)_getch();

	return false;
}

Bomb::~Bomb()
{
}
