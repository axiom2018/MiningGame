#pragma once

/* Reasoning for this class:

This class will handle a few of the abstraction pointers in an array and give us a place to quickly access them, their coordinates on the grid as well as other things
that may be useful.


																				Class member variables:

1) Reasoning for k_arrSize:

The size of the array, the maximum number of "entities" we'll have on screen.


2) Reasoning for k_maxItems:

When creating grounds (refined abstractions) we'll randomly decide what concrete implementation to give it.


3) Reasoning for m_pMineAbstractions:

The array that will be the abstractions that'll contain different things.


4) Reasoning for m_pPlayerX & m_pPlayerY:

The player position is needed because once we go start making positions for the mines, we don't want to have the same position as the player.


5) Reasoning for m_pPlayer:

We save the player to be able for the implementations.


6) Reasoning for m_pGridX & m_pGridY:

To properly place the mines we need to know the dimensions of the grid.


7) Reasoning for m_mineX & m_mineY:

Keep the position of the mines to cross check with other mines.



																				Class functions:

1) Reasoning for constructor:

We need the x and y position of the player.


2) Reasoning for Draw:

Draw mines.


3) Reasoning for DigMine:

Takes the x and y of the current players position and attempts to see if the player is ON a mine. If so, it'll execute the implementation INSIDE the abstraction.


4) Reasoning for CreateNewMines:

When we go to a new level, we'll need to do some clean up possibly with current mines and make new ones.


) Reasoning for destructor:

Delete memory.


																				Class functions (private):

1) Reasoning for FindVacantPosition:

Find an empty position for each mine.


2) Reasonign for GetRandomImp:

It will get a random implementation for the abstraction mostly, it will always FIRST grab a key.


*/

class MineManager
{
private:
	static const int k_arrSize = 5;
	static const int k_maxItems = 2;
	class MineAbs* m_pMineAbstractions[k_arrSize];
	int* m_pPlayerX;
	int* m_pPlayerY;
	class Player & m_pPlayer;
	int* m_pGridX;
	int* m_pGridY;
	int m_mineX;
	int m_mineY;

	class MineImp* GetRandomImp() const;
	void FindVacantPosition();
public:
	MineManager(int * pGridWidth, int * pGridHeight, class Player & pPlayer);
	bool Draw(const int& x, const int& y) const;
	void DigMine(const int& x, const int& y);
	void CreateNewMines();
	~MineManager();
};

