#pragma once
#include "Enemies.h"

class Viral : public Enemies
{
public:
	Viral(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth);
};

