#pragma once
#include "GridGenerator.h"
#include "Levels.h"

/* Reasoning for this class:

Manages the entire game, uses a singleton design pattern that doesn't dynamically allocate memory.


																				Class member variables:

1) Reasoning for m_gridGenerator:

Generates field/grid/2d array to play on.


2) Reasoning for m_pGate:

This is the thing the player will have to get to on screen to go to the next level.


3) Reasoning for m_pMineManager:

This is the mine system that the player will search for. See the bridge design pattern for more details.


4) Reasoning for m_pPlayer:

The player of the game. Dynamically allocated to be able to get the field width and height dimensions without using the constructors member initialization list.


5) Reasoning for m_pGrid:

The 2d grid the game will be on.


6) Reasoning for m_pX & m_pY:

The dimensions from the grid that will be saved in this class.


7) Reasoning for m_gameRunning:

This boolean will be true and keep the game running until the player wants to quit.


8) Reasoning for m_levelManager:

Handle all level related business.


																				Class functions:

1) Reasoning for copy constructor:

Delete it so this singleton can't be copied, ruining the purpose of a singleton.


2) Reasoning for Get:

Same as the typical "GetInstance" function of a Singleton design pattern.


3) Reasoning for DigMine:

when the player wants to dig a mine, this is called from Player.cpp.


4) Reasoning for Update:

Update game.


5) Reasoning for destructor:

Delete memory.

																				Class functions (private):

1) Reasoning for constructor:

Typical of the singleton design pattern.


2) Reasoning for Display:

Show the world.

*/

class World
{
private:
	GridGenerator m_gridGenerator;
	class Gate * m_pGate;
	class MineManager * m_pMineManager;
	class Player * m_pPlayer;
	char* m_pGrid;
	int* m_pX;
	int* m_pY;
	bool m_gameRunning;
	Levels m_levelManager;

	bool Display();
	World();
public:
	World(const World&) = delete;
	static World& Get();
	void DigMine(const int& x, const int& y) const;
	void Update();
	~World();
};

