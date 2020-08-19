#include "Positions.h"

Positions::Positions()
{

}

void Positions::AddPosition(const int& x, const int& y)
{
	m_positions.push_back(std::make_pair(x, y));
}

bool Positions::IsPositionOccupied(const int& x, const int& y)
{
	// Loop through and check all positions we currently have for a match.
	for (unsigned int i = 0; i < m_positions.size(); ++i)
	{
		if (x == m_positions.at(i).first && y == m_positions.at(i).second)
		{
			return true;
		}
	}

	return false;
}

void Positions::ClearPositions()
{
	m_positions.clear();
}

Positions& Positions::Get()
{
	static Positions s_positions;
	return s_positions;
}

void Positions::IAddPosition(const int& x, const int& y)
{
	Get().AddPosition(x, y);
}

bool Positions::IIsPositionOccupied(const int& x, const int& y)
{
	if (Get().IsPositionOccupied(x, y))
	{
		return true;
	}

	return false;
}

void Positions::IClearPositions()
{
	Get().ClearPositions();
}
