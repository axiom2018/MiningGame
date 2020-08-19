#include "World.h"
#include "Player.h"
#include "MineManager.h"
#include "EnemyManager.h"
#include "Gate.h"
#include "Positions.h"
#include "Item.h"
#include <iostream>
#include <conio.h>

World::World()
{
	// Set to true so the game runs.
	m_gameRunning = true;

	// Save the grid here and it's dimensions.
	m_pGrid = m_gridGenerator.GetGrid();
	m_pX = m_gridGenerator.GetGridWidth();
	m_pY = m_gridGenerator.GetGridHeight();

	// Initialize gate, for win condition.
	m_pGate = new Gate;

	// Initialize player by getting the max width (x) and max height (y) of the grid.
	m_pPlayer = new Player(m_gridGenerator.GetGridWidth(), m_gridGenerator.GetGridHeight(), &m_gameRunning, m_pGate);

	// Initialize the enemy manager then create enemies.
	EnemyManager::Get().SetData(m_pPlayer->GetX(), m_pPlayer->GetY(), m_gridGenerator.GetGridWidth(), m_gridGenerator.GetGridHeight(), m_pPlayer->GetHealth());

	// Initialize the mine manager.
	m_pMineManager = new MineManager(m_gridGenerator.GetGridWidth(), m_gridGenerator.GetGridHeight(), *m_pPlayer);
}

bool World::Display()
{
	system("cls");

	for (int y = 0; y < *m_pY; ++y)
	{
		for (int x = 0; x < *m_pX; ++x)
		{
			// If this position is the players, draw it.
			if (x == *m_pPlayer->GetX() && y == *m_pPlayer->GetY())
			{
				m_pPlayer->Draw();
			}

			//  && m_pPlayer->HasKey()
			else if (m_pGate->HasReachedGate())
			{
				system("cls");

				// Advance a level.
				m_levelManager.NextLevel();

				// Go ahead and create the new grid.
				m_gridGenerator.CreateNewGrid();

				// Set the new grid as well.
				m_pGrid = m_gridGenerator.GetGrid();

				// Clear all positions since nothing is taken up yet besides the player and the grid spots..
				Positions::IClearPositions();

				// The key is the most important item so reset that through the item interface.
				Item::ToggleCreatedKey();

				// Reset player to their starting position.
				m_pPlayer->ResetPosition();

				// We need knew mines for the next level.
				m_pMineManager->CreateNewMines();

				// Reset the enemy system.
				EnemyManager::Get().ResetEnemies();

				return true;
			}

			// If this position is a mine, draw it.
			else if (m_pMineManager->Draw(x, y))
			{
				continue;
			}

			// If this position is an enemy, draw it.
			else if (EnemyManager::Get().Draw(x, y))
			{
				continue;
			}

			// If this position is the gate, draw it.
			else if (m_pGate->Draw(x, y))
			{
				continue;
			}

			else
			{
				std::cout << m_pGrid[x + y * x] << " ";
			}
		}

		std::cout << "\n";
	}

	return false;
}

World& World::Get()
{
	static World s_world;
	return s_world;
}

void World::DigMine(const int& x, const int& y) const
{
	m_pMineManager->DigMine(x, y);
}

void World::Update()
{
	// As long as the game is still running, the player isn't dead and we haven't beat the last level, continue.
	while (m_gameRunning && !m_pPlayer->IsDead() && !m_levelManager.IsGameOver())
	{
		if (Display())
		{
			continue;
		}

		m_levelManager.ShowLevel();

		if (m_pPlayer->Update())
		{
			continue;
		}

		EnemyManager::Get().Update();
	}

	// Give dying message just incase player lost.
	if (m_pPlayer->IsDead())
	{
		system("cls");
		Display();
		std::cout << "\nYou died! Best of luck next time! (Press any key to exit)\n\n";
		(void)_getch();
	}

	else if (m_levelManager.IsGameOver())
	{
		std::cout << "You survived and made it out of the mine. :D Congrats! Game over.\n";
		(void)_getch();
	}
}

World::~World()
{
	delete m_pGate;
	m_pGate = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pMineManager;
	m_pMineManager = nullptr;
}
