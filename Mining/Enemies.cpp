#include "Enemies.h"
#include <math.h>
#include <iostream>

Enemies::Enemies()
{	
	// Enemy position.
	m_x = 0;
	m_y = 0;

	// Character of enemy.
	m_char = ' ';

	// Pointers to save player position.
	m_pPlayerX = nullptr;
	m_pPlayerY = nullptr;

	// Pointers to save grid dimensions.
	m_pGridX = nullptr;
	m_pGridY = nullptr;

	// Distance calculated using the pythagorean theorem to determine when the enemy should attack.
	m_distance = 0;

	// The minimum distance player has to be in order for the enemy to detect them.
	m_detectionDistance = 0;

	// The "cant move" functionality relates to the siren stopping the enemies.
	m_cantMoveDuration = 0;

	// The boolean helps so we take 1 step to not decrement the cant move duration because player is still looking at the
	m_pause = false;

	// The maximum time it takes for the enemy to move.
	m_delay = 0;

	// Same as delay but delay holds the max, this will be decremented.
	m_tempDelay = 0;

	// Set the health to initially nullptr.
	m_pPlayerHealth = nullptr;

	// Damage to apply to the player.
	m_damage = 0;
}

void Enemies::CalcDistPythagorasTheorem()
{
	// Theorem is a^2 + b^2 = c^2 (in a 2d world). To find c, start by getting side b.
	int b = m_y - *m_pPlayerY;

	// Then a.
	int a = m_x - *m_pPlayerX;

	// Once we have a and b, let's calculate each of their squared values.
	int a2 = a * a;
	int b2 = b * b;

	// Add the 2 squared variables together.
	int added = a2 + b2;

	// Set the distance.
	m_distance = int(round(sqrt(added))) - 1;
}

void Enemies::MoveToPlayer()
{
	// Check if we have to go bottom right.
	if (m_x < *m_pPlayerX && m_y < *m_pPlayerY)
	{
		// If true, go bottom right.
		++m_x;
		++m_y;
	}

	// Check if we have to go bottom left.
	else if (m_x > *m_pPlayerX&& m_y < *m_pPlayerY)
	{
		--m_x;
		++m_y;
	}

	// Check if we have to go top right.
	else if (m_x < *m_pPlayerX && m_y > *m_pPlayerY)
	{
		++m_x;
		--m_y;
	}

	// Check if we have to go top left.
	else if (m_x > *m_pPlayerX && m_y > *m_pPlayerY)
	{
		--m_x;
		--m_y;
	}

	// Left.
	else if (m_x > *m_pPlayerX && m_y == *m_pPlayerY)
	{
		--m_x;
	}

	// Right.
	else if (m_x < *m_pPlayerX && m_y == *m_pPlayerY)
	{
		++m_x;
	}

	// Up.
	else if (m_x == *m_pPlayerX && m_y > *m_pPlayerY)
	{
		--m_y;
	}

	// Down.
	else if (m_x == *m_pPlayerX && m_y < *m_pPlayerY)
	{
		++m_y;
	}
}

bool Enemies::IsMovementDelayed()
{
	if (m_tempDelay > 0)
	{
		--m_tempDelay;
		return false;
	}

	m_tempDelay = m_delay;

	return true;
}

bool Enemies::CollisionWithPlayer() const
{
	if (m_x == *m_pPlayerX && m_y == *m_pPlayerY)
	{
		return true;
	}

	return false;
}

void Enemies::DoDamage()
{
	int result = *m_pPlayerHealth - m_damage;

	// Check if below 0.
	if (result < 0)
	{
		// If so, just set player health to 0.
		*m_pPlayerHealth = 0;
	}

	else
	{
		// If not, set to result.
		*m_pPlayerHealth = result;
	}
}

void Enemies::HaltMovement(const int& steps)
{
	// Set the state to be on.
	m_movementBlocked.m_entityState = true;

	// Set the amount of steps to get through before enemy can move again.
	m_cantMoveDuration = steps;

	// Explained in header.
	m_pause = true;
}

void Enemies::Reset(const int& x, const int& y)
{
	// Set the state to false.
	m_movementState.m_entityState = false;
	m_x = x;
	m_y = y;
}

bool Enemies::Draw(const int& x, const int& y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_char << " ";
		return true;
	}

	return false;
}

void Enemies::Update()
{
	// Check if movement state has been altered.
	if (m_movementBlocked.m_entityState)
	{
		// Exit if true, must decrement when player can see the screen.
		if (m_pause)
		{
			m_pause = false;
			return;
		}
		
		// If duration is 0, enemy can move again, set the boolean to false.
		if (m_cantMoveDuration <= 0)
		{
			m_movementBlocked.m_entityState = false;
		}

		else
		{
			// If not, just decrement the duration.
			--m_cantMoveDuration;
			return;
		}
	}

	// If the enemy detected player, attack player.
	if (m_movementState.m_entityState)
	{
		// Check if movement is delayed first.
		if (IsMovementDelayed())
		{
			// Then begin moving.
			MoveToPlayer();

			// Check for collision here.
			if (CollisionWithPlayer())
			{
				// And if collision is there, apply damage.
				DoDamage();
			}
		}

		return;
	}

	// Since we have the player x and y, we should calculate if the player is close enough for the enemy to change their state.
	CalcDistPythagorasTheorem();

	// Check if the detection distance has been reached.
	if (m_distance <= m_detectionDistance)
	{
		// Change the state.
		m_movementState.m_entityState = true;

		// Check if movement is delayed first.
		if (IsMovementDelayed())
		{
			// Then begin moving.
			MoveToPlayer();
		}
	}
}
