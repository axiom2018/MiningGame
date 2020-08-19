#pragma once
#include "Enemies.h"


class Clicker : public Enemies
{
public:
	Clicker(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth);
};

