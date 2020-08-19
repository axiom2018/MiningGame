#include "Player.h"
#include "World.h"
#include <iostream>
#include <conio.h>

Player::Player(int* pX, int* pY, bool* pGameRunning, class Gate* pGate) :
	m_inventory(&m_health, pGate)
{
	// Save dimensions of the grid and also set the players starting position.
	m_pGridX = pX;
	m_pGridY = pY;
	m_x = *m_pGridX - 1;
	m_y = *m_pGridY - 1;

	// Set the player icon.
	m_player = '&';

	// Save the boolean to change it incase the player wants to quit.
	m_pGameRunning = pGameRunning;

	// Set the health.
	m_health = 100;

	// Save to display in instructions.
	m_gateSymbol = '#';
}

void Player::MoveUp()
{
	// Check the bounds.
	if (m_y - 1 < 0)
	{
		return;
	}

	--m_y;
}

void Player::MoveDown()
{
	// Check the bounds.
	if (m_y + 1 >= * m_pGridY)
	{
		return;
	}

	++m_y;
}

void Player::MoveLeft()
{
	// Check the bounds.
	if (m_x - 1 < 0)
	{
		return;
	}

	--m_x;
}

void Player::MoveRight()
{
	// Check the bounds.
	if (m_x + 1 >= * m_pGridX)
	{
		return;
	}

	++m_x;
}

void Player::Instructions() const
{
	std::cout << "\nHealth: " << m_health << "\n";
	std::cout << "The gate (symbol " << m_gateSymbol << ")" << " can ONLY be reached if you found the key.\n";
	std::cout << "w/a/s/d - Moves player.     m - Attempts to mine ore.     i - Opens inventory screen. \n";
	std::cout << "~~~When you're AT the gate, press the 'U/u' key to unlock it and go to the next level!~~~\n";
}

int * Player::GetX()
{
	return &m_x;
}

int * Player::GetY()
{
	return &m_y;
}

int* Player::GetHealth()
{
	return &m_health;
}

void Player::Damage(const int& damage)
{
	// Subtract from health.
	m_health = m_health - damage;

	// Check if health is at or below 0, if so, game over.
	if (m_health <= 0)
	{
		m_health = 0;
	}
}

void Player::IncreaseCurrentHealth(const int& increase)
{
	m_health += increase;
}

bool Player::IsDead() const
{
	if (m_health <= 0)
	{
		return true;
	}

	return false;
}

void Player::AddItem(Item* pItem)
{
	m_inventory.AddItem(pItem);
}

void Player::ResetPosition()
{
	m_x = *m_pGridX - 1;
	m_y = *m_pGridY - 1;
}

bool Player::IsInventoryFull() const
{
	if (m_inventory.IsFull())
	{
		return true;
	}

	return false;
}

void Player::Draw() const
{
	std::cout << m_player << " ";
}

bool Player::Update()
{
	Instructions();

	// Get input with the getch function and then process with the switch.
	char input = _getch();

	/* For the player to attempt to MINE, we must give the player position to the mine manager and then see if
	any mine position matches that. */
	switch (input)
	{
	case 'w':
		MoveUp();
		break;
	case 's':
		MoveDown();
		break;
	case 'a':
		MoveLeft();
		break;
	case 'd':
		MoveRight();
		break;
	case 'm':
		World::Get().DigMine(m_x, m_y);
		break;
	case 'i':
		m_inventory.OpenInventoryScreen();
		break;
	case 'u':
		return m_inventory.UseKey(m_x, m_y);
	case 'q':
		*m_pGameRunning = false;
		break;
	default:
		break;
	}

	return false;
}