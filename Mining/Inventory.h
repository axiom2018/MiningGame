#pragma once
#include <vector>

/* Reasoning for this class:

Inventory system for the player to make use of.


																				Class member variables:

1) Reasoning for k_maxSize:

Make sure we can't add anymore items if we're already at the max.


2) Reasoning for m_currentSize:

Keep track of how many items in inventory.


3) Reasoning for m_pItems:

The structure that will hold the items.


4) Reasoning for m_foundKey:

Lets the World.cpp file know if the key has been found so player moves to next level.


5) Reasoning for m_index:

The index the symbol is currently on to select an item.


6) Reasoning for m_pPlayerHealth:

To give the player more health points for their healthpack.


7) Reasoning for m_pGate:

Go ahead and save it in the constructor to assign it to the variant struct when need be for the key to open the gate.


																				Class functions:

1) Reasoning for constructor:

Initialize variables.


2) Reasoning for AddItem:

Set item in inventory vector.


3) Reasoning for OpenInventoryScreen:

To open the inventory and needs player because we could alter the players health.


4) Reasoning for UseKey:

When the player has the key, they'll be able to use it with keys.


5) Reasoning for IsFull:

Tell if it's full just incase we want to get an item but the space is done.


) Reasoning for destructor:

Delete memory.



																				Class functions (private):

1) Reasoning for Instructions:

Show how to use the inventory.


2) Reasoning for GetInput:

Take in input for the inventory.


3) Reasoning for MoveUp & MoveDown:

Directions on the inventory.


4) Reasoning for SelectItem:

Choose the item.


*/

class Inventory
{
private:
	static const int k_maxSize = 5;
	int m_currentSize;
	std::vector<class Item*> m_pItems;
	bool m_foundKey;
	int m_index;
	int* m_pPlayerHealth;
	class Gate* m_pGate;

	void SelectItem();
	void MoveDown();
	void MoveUp();
	bool GetInput();
	void Instructions() const;
public:
	Inventory(int* pPlayerHealth, class Gate* pGate);
	void AddItem(class Item* pItem);
	void OpenInventoryScreen();
	bool UseKey(const int& playerX, const int& playerY);
	bool IsFull() const;
	~Inventory();
};

