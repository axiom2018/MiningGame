#include "MineManager.h"
#include "MineAbs.h"
#include "Ground.h"
#include "Bomb.h"
#include "ItemFound.h"
#include "Player.h"
#include "Item.h"
#include "Key.h"
#include "Positions.h"
#include <iostream>
#include <conio.h>

MineManager::MineManager(int* pGridWidth, int* pGridHeight, Player& pPlayer) :
	m_pPlayer(pPlayer)
{
	// Save the position.
	m_pPlayerX = pPlayer.GetX();
	m_pPlayerY = pPlayer.GetY();

	// And grid dimensions.
	m_pGridX = pGridWidth;
	m_pGridY = pGridHeight;

	// Set the mine pos to 0 to start, we'll find real positions later.
	m_mineX = 0;
	m_mineY = 0;

	// Keeping a local variable so we add as much mines regarding the total size of the array.
	int total = 0;

	// By default, make sure the pointers are nullptr.
	for (int i = 0; i < k_arrSize; ++i)
	{
		m_pMineAbstractions[i] = nullptr;
	}

	// Now we start getting the mines ready.
	while (total < k_arrSize)
	{
		// Get a random position for the mine.
		FindVacantPosition();

		// Create a new mine now with the coordinates.
		m_pMineAbstractions[total] = new Ground(m_mineX, m_mineY, GetRandomImp());

		++total;
	}
}

void MineManager::FindVacantPosition()
{
	while (true)
	{
		// Get random x and random y for the mines.
		m_mineX = 0 + (rand() % *m_pGridX);
		m_mineY = 0 + (rand() % *m_pGridY);

		// Check if these collide with player position, or if position is registered already, or if it's the default position for the gate.
		if ((m_mineX == *m_pPlayerX && m_mineY == *m_pPlayerY) ||
			Positions::IIsPositionOccupied(m_mineX, m_mineY) ||
			(m_mineX == 0 && m_mineY == 0))
		{
			m_mineX = 0;
			m_mineY = 0;
			continue;
		}

		else
		{
			// We found one. Add it to the positions.
			Positions::IAddPosition(m_mineX, m_mineY);
			break;
		}
	}
}

MineImp* MineManager::GetRandomImp() const
{
	// Check here with a static function in item interface if we've already created the key. If not, do so immediately because 1 MUST be present at every level.
	if (!Item::CreatedKey())
	{
		// We'll return the key but first set the boolean to true.
		Item::ToggleCreatedKey();

		// Create the key.
		return new ItemFound(new Key);
	}

	// We need the maximum items we have, currently it's 2. Then get a random number between that and use a switch statement. 
	int value = 1 + (rand() % k_maxItems);

	switch (value)
	{
	case 1:
		return new Bomb;
	case 2:
		return new ItemFound;
	default:
		break;
	}

	return nullptr;
}

bool MineManager::Draw(const int& x, const int& y) const
{
	// Loop through to see if we have matching coordinates.
	for (int i = 0; i < k_arrSize; ++i)
	{
		// Check for nullptr, because after we successfully dig a mine, we'll delete it from the array.
		if (m_pMineAbstractions[i] != nullptr && m_pMineAbstractions[i]->Draw(x, y))
		{
			return true;
		}
	}

	return false;
}

void MineManager::DigMine(const int& x, const int& y) 
{
	// After we attempt to dig for an actual mine, regardless of if its a bomb or item, we must remove it from the array. It's done for now.
	for (int i = 0; i < k_arrSize; ++i)
	{
		if (m_pMineAbstractions[i] != nullptr && x == m_pMineAbstractions[i]->GetX() && y == m_pMineAbstractions[i]->GetY())
		{
			// We found a match. Go ahead and execute the implementation behind the abstraction.
			if (!m_pMineAbstractions[i]->Execute(m_pPlayer))
			{
				delete m_pMineAbstractions[i];
				m_pMineAbstractions[i] = nullptr;
			}

			return;
		}
	}

	// If player not at mine location send message letting them know.
	std::cout << "No mine found here!\n";
}

void MineManager::CreateNewMines()
{
	// Set the mine pos to 0 to start, we'll find real positions later.
	m_mineX = 0;
	m_mineY = 0;

	// If certain ones are NOT nullptr, we can place them elsewhere in the NEW level.
	for (int i = 0; i < k_arrSize; ++i)
	{
		// Let's just change it's coordinates to fit the new grid coordinates.
		FindVacantPosition();

		// Is there already an item here? 
		if (m_pMineAbstractions[i] != nullptr)
		{
			// Then set the position.
			m_pMineAbstractions[i]->ResetPosition(m_mineX, m_mineY);
		}

		// If no item we can create a new one.
		else
		{
			// Create a new mine now with the coordinates.
			m_pMineAbstractions[i] = new Ground(m_mineX, m_mineY, GetRandomImp());
		}
	}
}

MineManager::~MineManager()
{
	for (int i = 0; i < k_arrSize; ++i)
	{
		delete m_pMineAbstractions[i];
		m_pMineAbstractions[i] = nullptr;
	}
}
