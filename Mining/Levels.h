#pragma once

/* Reasoning for this class: 

Keep track of the current level the game is on.


																				Class member variables:

1) Reasoning for m_level:

The current level the game is on.


2) Reasoning for m_maxLevels:

The max amount of levels to be played.


																				Class functions:

1) Reasoning for constructor:

Initialize the variables.


2) Reasoning for NextLevel:

Increment the m_level variable by one since the desire is to go to next level.


3) Reasoning for IsGameOver:

If the current level is equal to or higher than max, the game is over.


4) Reasoning for ShowLevel:

Display level player is currently on.


																				Class functions (private):

1)


*/

class Levels
{
private:
	int m_level;
	int m_maxLevels;
public:
	Levels();
	void NextLevel();
	bool IsGameOver() const;
	void ShowLevel() const;
};

