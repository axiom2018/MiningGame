#include "Levels.h"
#include <iostream>

Levels::Levels()
{
	m_level = 1;
	m_maxLevels = 6;
}

void Levels::NextLevel()
{
	// Do this is the current level is less than the max.
	if (m_level < m_maxLevels)
	{
		++m_level;
	}
}

bool Levels::IsGameOver() const
{
	if (m_level >= m_maxLevels)
	{
		return true;
	}

	return false;
}

void Levels::ShowLevel() const
{
	std::cout << "----------Current level: " << m_level << " out of " << m_maxLevels - 1 << ".----------";
}