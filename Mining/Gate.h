#pragma once

/* Reasoning for this class:

Gates are where the player should get to in order to get to the next level.

																				Class member variables:

1) Reasoning for k_gateChar:

The symbol of the gate on screen.


2) Reasoning for m_x & m_y:

The gate has a position of course.


3) Reasoning for m_hasReachedGate:

Keep the custom state system


																				Class functions:

1) Reasoning for constructor:

Initialize position.


2) Reasoning for GetX & GetY:

Get the position, primarily in Inventory.cpp so we know when we can use the key.


3) Reasoning for ReachedGate:

In Key.cpp, we call this function to indicate the gate it now open.


4) Reasoning for HasReachedGate:

Check if player has reached the gate.


5) Reasoning for Draw:

Draw the symbol, will be given the grid coordinates, if the coordinates match then we draw.


																				Class functions (private):

1)


*/

class Gate
{
private:
	static const char k_gateChar = '#';
	int m_x;
	int m_y;
	bool m_hasReachedGate;
public:
	Gate();
	int GetX() const;
	int GetY() const;
	void ReachedGate();
	bool HasReachedGate();
	bool Draw(const int& x, const int& y) const;
};

