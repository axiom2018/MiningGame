#pragma once
#include "Enemies.h"

class DeathClaw : public Enemies
{
public:
	DeathClaw(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth);
};

