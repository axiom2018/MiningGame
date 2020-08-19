#include "Viral.h"
#include <iostream>

Viral::Viral(const int& x, const int& y, int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth)
{
	// Set the position and other variables.
	m_x = x;
	m_y = y;
	m_pPlayerX = pPlayerX;
	m_pPlayerY = pPlayerY;
	m_pGridX = pGridX;
	m_pGridY = pGridY;
	m_pPlayerHealth = pPlayerHealth;
	
	// Set the character this enemy will use to display themselves.
	m_char = '@';

	// The distance that will be required for the player to be in before the enemy attacks.
	m_detectionDistance = 2;

	// Damage to give to player.
	m_damage = 15;

	// Delay is important for the enemy to charge at you so often a certain amount of times.
	m_delay = 2;
	m_tempDelay = m_delay;

	// Calculate the distance with the helper function.
	CalcDistPythagorasTheorem();
}