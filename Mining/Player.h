#pragma once
#include "Inventory.h"

/* Reasoning for this class:

Controls the player.

																				Class member variables:

1) Reasoning for m_pGridX & m_pGridY:

The dimensions of the grid, the max width and height.


2) Reasoning for m_x & m_y:

The actual position of the player.


3) Reasoning for m_player:

The player symbol drawn on the grid.


4) Reasoning for m_pGameRunning:

When the player wants to quit, they'll alter this boolean pointer which is created in the world and therefore end the game.


5) Reasoning for m_health:

Player can die due to damage.


6) Reasoning for m_inventory:

The players inventory.


7) Reasoning for k_gateSymbol:

Save the gate symbol to display in instructions.



																				Class functions:

1) Reasoning for constructor:

Set dimensions, x and y axis or width and height.


2) Reasoning for GetX & GetY:

Get the position so in the world, we know where to draw the player.


3) Reasoning for GetHealth:

So enemies do damage.


4) Reasoning for Damage:

The bombs in the game give the player the potential to be damaged.


5) Reasoning for IncreaseCurrentHealth:

The item healthpack will call this because it'll need to alter the health.


6) Reasoning for IsDead:

In World.cpp check if player is dead to continue game.


7) Reasoning for AddItem:

Add item to players inventory.


8) Reasoning for HasKey:

For the next level to be prepared we need to check if the player even has a key when they hit the gate.


9) Reasoning for ResetPosition:

When we generate a new grid we always start at the bottom right.


10) Reasoning for IsInventoryFull:

Before adding an item, must check if we're full.


11) Reasoning for Draw:

Display player.


12) Reasoning for Update:

Get input from the player.

																				Class functions (private):

1) Reasoning for MoveUp/Down/Left/Right:

Simple movement functions for the player.


2) Reasoning for instructions:

Show how to play the game.

*/

class Player
{
private:
	int* m_pGridX;
	int* m_pGridY;
	int m_x;
	int m_y;
	char m_player;
	bool* m_pGameRunning;
	int m_health;
	Inventory m_inventory;
	char m_gateSymbol;

	void Instructions() const;
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
public:
	Player(int * pX, int * pY, bool * pGameRunning, class Gate * pGate);
	int* GetX();
	int* GetY();
	int* GetHealth();
	void Damage(const int& damage);
	void IncreaseCurrentHealth(const int& increase);
	bool IsDead() const;
	void AddItem(class Item* pItem);
	void ResetPosition();
	bool IsInventoryFull() const;
	void Draw() const;
	bool Update();
};

