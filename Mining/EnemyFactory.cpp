#include "EnemyFactory.h"
#include "Viral.h"
#include "Clicker.h"
#include "DeathClaw.h"
#include <stdlib.h>

Enemies* EnemyFactory::CreateEnemy(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth)
{
	// we'll create random enemies based on a random numerical value.
	int value = 1 + (rand() % 100);

	// Each enemy will be created based on the number. So one might be more likely than another.
	if (value <= 20)
	{
		return new DeathClaw(x, y, pPlayerX, pPlayerY, pGridX, pGridY, pPlayerHealth);
	}

	else if (value > 20 && value <= 60)
	{
		return new Viral(x, y, pPlayerX, pPlayerY, pGridX, pGridY, pPlayerHealth);
	}
	
	else if (value > 60)
	{
		return new Clicker(x, y, pPlayerX, pPlayerY, pGridX, pGridY, pPlayerHealth);
	}

	return nullptr;
}
