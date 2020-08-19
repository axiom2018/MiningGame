#pragma once

/* Reasoning for this class:

The implementation base class in the bridge design pattern.

																				Class member variables:

1)


																				Class functions:

1) Reasoning for Execute:

When the player presses the key to mine, this will be called to see what happens to or for the play.


																				Class functions (private):

1)


*/

class MineImp
{
public:
	virtual bool Execute(class Player& pPlayer) = 0;
	virtual ~MineImp() {};
};

