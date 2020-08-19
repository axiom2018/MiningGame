#include "Item.h"
#include "Player.h"
#include "HealthPack.h"
#include "Key.h"
#include "Siren.h"
#include <iostream>

// Initialize the static variables here.
bool Item::m_createdKey = false;

Item::Item(const bool& isKey)
{
	m_isKey = isKey;
}

Item* Item::CreateItem()
{
	// we'll create random enemies based on a random numerical value.
	int value = 1 + (rand() % 100);

	// Each enemy will be created based on the number. So one might be more likely than another.
	if (value <= 35)
	{
		return new Siren;
	}

	else if (value > 35)
	{
		return new HealthPack;
	}

	return nullptr;
}

bool Item::CreatedKey()
{
	if (m_createdKey)
	{
		return true;
	}

	return false;
}

void Item::ToggleCreatedKey()
{
	m_createdKey = !m_createdKey;
}

