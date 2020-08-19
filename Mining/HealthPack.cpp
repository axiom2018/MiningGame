#include "HealthPack.h"
#include <variant>
#include <iostream>

HealthPack::HealthPack() :
	Item(false)
{

}

const char * HealthPack::GetName() const
{
	return "Healthpack";
}

bool HealthPack::IsKey() const
{
	return false;
}

Type HealthPack::GetType() const
{
	return Type::Health;
}

void HealthPack::ShowDescriptionOfItem() const
{
	std::cout << "     Heal yourself by " << k_amountToHeal << "\n";
}

void HealthPack::Execute(iItem item)
{
	// We'll do one check to make SURE this is the right type we need in here.
	if (auto value = std::get_if<int*>(&item.m_var))
	{
		// Get it out of the auto variable.
		int* pPlayerHealth = *value;

		// Then make a temporary variable to hold the health plus what it'll be with healing.
		int totalHealth = *pPlayerHealth + k_amountToHeal;

		// Check if it's greater than 100, because 100 is the health cap.
		if (totalHealth > 100)
		{
			// If so, just set to 100.
			*pPlayerHealth = 100;
		}

		else
		{
			// If not, set player health to total health.
			*pPlayerHealth = totalHealth;
		}
	}
}