#pragma once

/* Reasoning for this class:

A factory design pattern for quickly creating enemies. This is different from the item factory pattern because in the item one, it has derived classes
of it which are items. If I wanted that implementation I could of stuck this factory inside of the Enemies.h/.cpp files, but I wanted to keep it
separate.

																				Class member variables:



																				Class functions:

1) Reasoning for CreateEnemy:

Typical creation function in a factory pattern.


																				Class functions (private):

1)

*/

class EnemyFactory
{
public:
	static class Enemies* CreateEnemy(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth);
};

