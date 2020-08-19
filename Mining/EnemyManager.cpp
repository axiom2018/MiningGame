#include "EnemyManager.h"
#include "EnemyFactory.h"
#include "Positions.h"
#include "Enemies.h"
#include <iostream>

EnemyManager::EnemyManager()
{
	// The amount to create each level, will increase by 1 with every other level.
	m_amountOfEnemiesToCreate = 2;

	// Set position to 0 in the beginning.
	m_enemyX = 0;
	m_enemyY = 0;
}

void EnemyManager::GetEnemyPosition()
{
	while (true)
	{
		// Get a random position.
		m_enemyX = 0 + (rand() % *m_pGridX);
		m_enemyY = 0 + (rand() % *m_pGridY);

		// Check if these collide with player position, or if position is registered already, or if it's the default position for the gate.
		if ((m_enemyX == *m_pPlayerX && m_enemyY == *m_pPlayerY) ||
			Positions::IIsPositionOccupied(m_enemyX, m_enemyY) ||
			(m_enemyX == 0 && m_enemyY == 0))
		{
			m_enemyX = 0;
			m_enemyY = 0;
			continue;
		}

		else
		{
			// We found one. Add it to the positions.
			Positions::IAddPosition(m_enemyX, m_enemyY);
			break;
		}
	}
}

void EnemyManager::CreateEnemies()
{
	// If state is true, spawn 1 enemy.
	if (m_state.m_entityState)
	{
		SpawnEnemy();
	}

	// If not, the class was just initialized and we'll spawn the amount from the variable.
	else
	{
		for (int i = 0; i < m_amountOfEnemiesToCreate; ++i)
		{
			SpawnEnemy();
		}
	}
}

void EnemyManager::SpawnEnemy()
{
	// Find an enemy position.
	GetEnemyPosition();

	// Get the enemy.
	m_pEnemies.push_back(EnemyFactory::CreateEnemy(m_enemyX, m_enemyY, m_pPlayerX, m_pPlayerY, m_pGridX, m_pGridY, m_pPlayerHealth));
}

EnemyManager& EnemyManager::Get()
{
	static EnemyManager s_enemyManager;
	return s_enemyManager;
}

void EnemyManager::SetData(int* pPlayerX, int* pPlayerY, int* pGridX, int* pGridY, int* pPlayerHealth)
{
	// Set variables and create our first enemies.
	m_pPlayerX = pPlayerX;
	m_pPlayerY = pPlayerY;
	m_pGridX = pGridX;
	m_pGridY = pGridY;
	m_pPlayerHealth = pPlayerHealth;

	CreateEnemies();
}

void EnemyManager::ResetEnemies()
{
	// Reset enemy data of current enemies first.
	for (unsigned int i = 0; i < m_pEnemies.size(); ++i)
	{
		GetEnemyPosition();

		m_pEnemies.at(i)->Reset(m_enemyX, m_enemyY);
	}

	// If true, then add an enemy.
	if (m_state.m_entityState)
	{
		CreateEnemies();
	}

	// Toggle the state, and if true, we'll add an enemy.
	m_state.m_entityState = !m_state.m_entityState;
}

void EnemyManager::HaltMovement(const int& steps)
{
	for (unsigned int i = 0; i < m_pEnemies.size(); ++i)
	{
		m_pEnemies.at(i)->HaltMovement(steps);
	}
}

bool EnemyManager::Draw(const int& x, const int& y) const
{
	for (unsigned int i = 0; i < m_pEnemies.size(); ++i)
	{
		if (m_pEnemies.at(i)->Draw(x, y))
		{
			return true;
		}
	}

	return false;
}

void EnemyManager::Update() const
{
	for (unsigned int i = 0; i < m_pEnemies.size(); ++i)
	{
		m_pEnemies.at(i)->Update();
	}
}

EnemyManager::~EnemyManager()
{
	for (unsigned int i = 0; i < m_pEnemies.size(); ++i)
	{
		delete m_pEnemies.at(i);
		m_pEnemies.at(i) = nullptr;
	}
}
