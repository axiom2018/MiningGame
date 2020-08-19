#pragma once
#include <vector>

/* Reasoning for this class:

One central object to hold all enemy positions for cross checking.


																				Class member variables:
1) Reasoning for m_positions:

The vector of pairs of ints, which represent the x and y positions of the enemies.


																				Class functions:

1) Reasoning for copy constructor:

Delete it so this singleton can't be copied, ruining the purpose of a singleton.


2) Reasoning for IAddPosition:

Interface function to access the real function with double colons, like "Positions::FunctionToCallHere()"


2) Reasoning for IIsPositionOccupied:

Interface function to access the real function with double colons, like "Positions::FunctionToCallHere()"


3) Reasoning for ClearPositions:

Interface function to access the real function with double colons, like "Positions::FunctionToCallHere()"


																				Class functions (private):

1) Reasoning for constructor:

Typical of the singleton design pattern.


2) Reasoning for AddPosition:

Self explanatory.


3) Reasoning for IsPositionOccupied:

Check for matching position.


4) Reasoning for ClearPositions:

If we've beat the level, the new level begins, the old one resets, so we must get rid of the old positions.


*/

class Positions
{
private:
	std::vector<std::pair<int, int>> m_positions;

	void ClearPositions();
	bool IsPositionOccupied(const int& x, const int& y);
	void AddPosition(const int& x, const int& y);
	Positions();
public:
	Positions(const Positions&) = delete;
	static Positions& Get();
	static void IAddPosition(const int& x, const int& y);
	static bool IIsPositionOccupied(const int& x, const int& y);
	static void IClearPositions();
};