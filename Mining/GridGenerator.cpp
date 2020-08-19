#include "GridGenerator.h"
#include <iostream>

GridGenerator::GridGenerator()
{
	// Set the minimum and maximum values to get the right dimensions for the grid.
	m_min = 7;
	m_max = 13;

	// Get a value inbetween the min and max for the dimensions in the grid.
	m_x = m_min + (rand() % m_max);
	m_y = m_min + (rand() & m_max);

	// Then create the Grid.
	GenerateGrid();
}

void GridGenerator::GenerateGrid()
{
	// Initialize the memory.
	m_pGrid = new char[m_y * m_x];

	for (int y = 0; y < m_y; ++y)
	{
		for (int x = 0; x < m_x; ++x)
		{
			m_pGrid[x + y * x] = '.';
		}
	}
}

void GridGenerator::CreateNewGrid()
{
	// Delete the old Grid first before making a new one.
	delete[] m_pGrid;
	m_pGrid = nullptr;

	// Set the new x and y coordinates and generate.
	m_x = m_min + (rand() % m_max);
	m_y = m_min + (rand() & m_max);

	GenerateGrid();
}

int * GridGenerator::GetGridWidth()
{
	return &m_x;
}

int * GridGenerator::GetGridHeight() 
{
	return &m_y;
}

char* GridGenerator::GetGrid() const
{
	return m_pGrid;
}

GridGenerator::~GridGenerator()
{
	delete[] m_pGrid;
	m_pGrid = nullptr;
}
