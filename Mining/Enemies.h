#pragma once
#include "State.h"

/* Reasoning for this class:

The base class in the strategy pattern for the enemies.

																				Class member variables:

1) Reasoning for m_x & m_y:

The position of each enemy.


2) Reasoning for m_char:

The character they'll use to display themselves.


3) Reasoning for m_pPlayerX & m_pPlayerY:

Save player position to keep enemies updated.


4) Reasoning for m_pGridX & m_pGridY:

Save the dimensions so the enemies know bounds of the grid.


5) Reasoning for m_distance:

This is the distance required for the player to be in before the enemy gets alerted.


6) Reasoning for m_detectionDistance:

If the player gets this close, the enemy attacks.


7) Reasoning for m_movementState:

The state system to determine if the enemy moves toward you or not.


8) Reasoning for m_movementBlocked:

The enemy might not be able to move due to the Siren item.


9) Reasoning for m_cantMoveDuration:

This is how long they won't be able to move for.


10) Reasoning for m_pause:

When the Siren item is used, enemies can't move for a duration. But then in World.cpp and we update the enemies again, so before the player gets a chance to see
the screen again one count from the cant move duration goes down. We'll pause that we this.


11) Reasoning for m_delay & m_tempDelay:

Arguably the most important, it determines the SPEED at which the enemy moves to you.


12) Reasoning for m_pPlayerHealth:

Damage the player.


13) Reasoning for m_damage:

The rate of damage to apply to the player.


																				Class functions:

1) Reasoning for IsMovementDelayed:

Uses the delay variables to tell if the enemy movement is delayed, REALLY helps the game because without it the enemies are pretty much
going hyper speed at you.


2) Reasoning for CollisionWithPlayer:

Check for collision, if so, do damage to player.


3) Reasoning for DoDamage:

Do damage to the player.


4) Reasoning for HaltMovement:

Stop the movement if desired by n steps. 


5) Reasoning for Reset:

When creating a new level, make the position of the enemies fit the new grid.


6) Reasoning for Draw:

Draw the enemies.


7) Reasoning for Update:

Update the enemies.


																				Class functions (private/protected):

1) Reasoning for CalcDistPythagorasTheorem:

Calculate the distance between the 2 before enemy goes for the player.

*/

class Enemies
{
protected:
	int m_x;
	int m_y;
	char m_char;
	int* m_pPlayerX;
	int* m_pPlayerY;
	int* m_pGridX;
	int* m_pGridY;
	int m_distance;
	int m_detectionDistance;
	State m_movementState;
	State m_movementBlocked; 
	int m_cantMoveDuration;  
	bool m_pause;
	int m_delay;
	int m_tempDelay;
	int* m_pPlayerHealth;
	int m_damage;

	void MoveToPlayer();
	void CalcDistPythagorasTheorem();
public:
	Enemies();
	bool IsMovementDelayed();
	bool CollisionWithPlayer() const;
	void DoDamage();
	void HaltMovement(const int& steps);
	void Reset(const int& x, const int& y);
	bool Draw(const int& x, const int& y);
	void Update();
};