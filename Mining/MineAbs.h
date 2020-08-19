#pragma once

/* Reasoning for this class:

The implementation base class in the bridge design pattern.

																				Class member variables:

1) Reasoning for m_pMineImp:

Typical of the bridge design pattern to put the implementation in the base class of the abstraction.


2) Reasoning for k_displayChar:

The character the mines will take the form of on screen.


3) Reasoning for m_x & m_y:

These will have a position on screen in the grid.


																				Class functions:

1) Reasoning for constructor:

Initialize data.


2) Reasoning for GetX & GetY:

Needed in mine manager to see if a mine position matches the given player position.


3) Reasoning for ResetPosition:

Sets up another position according to the new grid for the abstraction.


3) Reasoning for Execute:

Handle what happens when the player presses key to try and dig.


4) Reasoning for Draw:

Display char.


																				Class functions (private):

1)


*/

class MineAbs
{
protected:
	class MineImp* m_pMineImp;
	static const char k_displayChar = '$';
	int m_x;
	int m_y;
public:
	MineAbs(const int& x, const int& y, class MineImp* pMineImp);
	int GetX() const;
	int GetY() const;
	void ResetPosition(const int& x, const int& y);
	virtual bool Execute(class Player & pPlayer) const = 0;
	virtual bool Draw(const int& x, const int& y) const = 0;
	virtual ~MineAbs() {};
};

