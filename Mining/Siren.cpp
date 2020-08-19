#include "Siren.h"
#include "EnemyManager.h"
#include <iostream>

Siren::Siren() :
	Item(false)
{
	m_stepsToDelayEnemies = 10;
}

const char* Siren::GetName() const
{
	return "Siren";
}

bool Siren::IsKey() const
{
	return false;
}

Type Siren::GetType() const
{
	return Type::Siren;
}

void Siren::ShowDescriptionOfItem() const
{
	std::cout << "     Make the enemies stop moving at you entirely for " << m_stepsToDelayEnemies << " button presses.\n";
}

void Siren::Execute(iItem item)
{
	// We'll do one check to make SURE this is the right type we need in here.
	if (auto value = std::get_if<class EnemyManager*>(&item.m_var))
	{
		// Get it out of the auto variable.
		EnemyManager * pEM = *value;

		// Delay the steps.
		pEM->HaltMovement(m_stepsToDelayEnemies);
	}
}
