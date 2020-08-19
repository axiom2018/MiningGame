#include "Gate.h"
#include <iostream>

Gate::Gate() 
{
	// Set the gates positions and save players position so we can do the check to see if they made it TO the gate.
	m_x = m_y = 0;

	// Boolean to control if the gate has been reached.
	m_hasReachedGate = false;
}

int Gate::GetX() const
{
	return m_x;
}

int Gate::GetY() const
{
	return m_y;
}

void Gate::ReachedGate()
{
	m_hasReachedGate = true;
}

bool Gate::HasReachedGate() 
{
	if (m_hasReachedGate)
	{
		// Once, in the world.cpp file that this returns true, it'll ready things for the new level. So let's set this to false again.
		m_hasReachedGate = false;
		return true;
	}

	return false;
}

bool Gate::Draw(const int& x, const int& y) const
{
	if (m_x == x && m_y == y)
	{
		std::cout << k_gateChar << " ";
		return true;
	}

	return false;
}