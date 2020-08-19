#pragma once

/* Reasoning for this class:

One place to generate the entire Grid/grid/map for the game, each level. Follows SRP.


																				Class member variables:

1) Reasoning for m_pGrid:

The 2d array that will be displayed in game.


2) Reasoning for m_x & m_y:

The rows and columns of the Grid.


3) Reasoning for m_min & m_max:

Set the dimensions with a minimum and maximum.


																				Class functions:

1) Reasoning for constructor:

Initialize the grid for the first time.


2) Reasoning for CreateNewGrid:

When we'd like to get a new grid to play the game on, this function will create a new one.


3) Reasoning for GetGridWidth & GetGridHeight:

Supply clients with the boundaries so they know the maximum movement.


4) Reasoning for GetGrid:

This class only GENERATES the grid. World will hold it and need to display it.


) Reasoning for destructor:

Deallocate memory.


																				Class functions (private):

1) Reasoning for GenerateGrid:

In the constructor we want to immediately get a Grid, so this function is called. Also this is called in the CreateNewGrid function.


*/

class GridGenerator
{
private:
	char* m_pGrid;
	int m_x;
	int m_y;
	int m_min;
	int m_max;

	void GenerateGrid();
public:
	GridGenerator();
	void CreateNewGrid();
	int* GetGridWidth();
	int* GetGridHeight();
	char* GetGrid() const;
	~GridGenerator();
};

