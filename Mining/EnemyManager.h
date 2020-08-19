#pragma once
#include "State.h"
#include <vector>

/* Reasoning for this class:

Manager of the entire enemy system.

																				Class member variables:

1) Reasoning for m_pPlayerX & m_pPlayerY:

Save player position to keep enemies updated.


2) Reasoning for m_pGridX & m_pGridY:

Save the dimensions so the enemies know bounds of the grid.


3) Reasoning for m_enemyX & m_enemyY:

The position of the enemy.


4) Reasoning for m_amountOfEnemiesToCreate:

We start off with an initial amount then increment it by 1.


5) Reasoning for m_pEnemies:

The vector containing all enemies.


6) Reasoning for m_pPlayerHealth:

Enemies damage player of course.


7) Reasoning for m_state:

We will add new enemies every so often. Every OTHER level to be exact. So on level 1, we'll have 2 enemies. Level 2? The same 2 enemies.
Level 3? Add 1 for a total of 3 enemies. Level 4? The same 3. Level 5, add 1 for a total of 4.


																				Class functions:

1) Reasoning for copy constructor:

Delete it so this singleton can't be copied, ruining the purpose of a singleton.


2) Reasoning for Get:

Same as the typical "GetInstance" function of a Singleton design pattern.


3) Reasoning for SetData:

We save the memory addresses of these 2 to let the enemies locate the player by pointers, so there's no need to keep passing the players position
over and over again making the enemy process a bit longer. We also must have the grid width and height or x and y so the enemies know the BOUNDS
of the grid. Also enemies must damage the player, so get its health as well.


4) Reasoning for ResetEnemies:

Reset their positions and states for a new grid.


5) Reasoning for HaltMovement:

The siren item will delay the enemy movement for x amount of time.


6) Reasoning for Draw:

Draw enemies.


7) Reasoning for Update:

Update their behavior.


) Reasoning for destructor:

Delete memory.



																				Class functions (private):

1) Reasoning for constructor:

Typical of the singleton design pattern.


2) Reasoning for GetEnemyPosition:

Get a position for the enemy that multiple functions can use.


3) Reasoning for CreateEnemies:

Depending on the state begin spawning enemies.


4) Reasoning for SpawnEnemy:

This core functionality was in multiple places but now resides in 1 function. Spawns 1 enemy when called.


*/

class EnemyManager
{
private:
	int* m_pPlayerX;
	int* m_pPlayerY;
	int* m_pGridX;
	int* m_pGridY;
	int m_enemyX;
	int m_enemyY;
	int m_amountOfEnemiesToCreate;
	std::vector<class Enemies*> m_pEnemies;
	int* m_pPlayerHealth;
	State m_state;

	void SpawnEnemy();
	void CreateEnemies();
	void GetEnemyPosition();
	EnemyManager();
public:
	EnemyManager(const EnemyManager&) = delete;
	static EnemyManager& Get();
	void SetData(int* pPlayerX, int* pPlayerY, int * pGridX, int * pGridY, int * pPlayerHealth);
	void ResetEnemies();
	void HaltMovement(const int& steps);
	bool Draw(const int& x, const int& y) const;
	void Update() const;
	~EnemyManager();
};

