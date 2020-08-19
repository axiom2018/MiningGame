#pragma once

/* Reasoning for this structure:

It represents the most basic binary state system we'll need in this game for the gates and enemies. I have to say this is definitely not the typical state
pattern as you'll see below. But it most definitely still works and functions properly AS a state system. 

Now the typical state pattern is what I've decided against in this game and you can find it here: https://refactoring.guru/design-patterns/state/cpp/example. 

As we can see we have the context class, the base class of the states and the 2 derived classes. Each derived class couples the context and the state it
wants to change too. Altogether there is SO much dynamic memory being used and allocated. It makes design sense to use it but it's slow. 

So the pros and cons of using this structure are as follows:

a) Pros
1 - Less dynamic memory used compared to the state design pattern, so much faster when the game runs.
2 - Simplier and easier to read. 

b) Cons
1 - Is complicated with the more states we'd might want to add so it doesn't scale as well.

																				Class member variables:

1) Reasoning for m_state:

The primary state, which is binary.


																				Class functions:

1) Reasoning for constructor:

Allow a default constructor to set the state.


*/

struct State
{
	bool m_entityState;

	State(bool startingState = false)
	{
		m_entityState = startingState;
	}
};