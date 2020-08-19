#include "ItemFound.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <conio.h>

ItemFound::ItemFound(Item* pKey)
{
	/* Boolean is needed to determine if we added the key or not. It helps with memory because the key pointer CAN be deleted here
	if it's not with the player and the player hasn't received it yet. If so, that's why we delete the key here because it's HELD
	in here. However, if the player has it, we don't want to delete it here because the key will be stored in the players inventory
	so we'll loop through and delete all of those, causing the key pointer to be junk and crash upon trying to delete it in the
	players inventory. */
	m_holdingKey = false;
	
	// Then initialize the key pointer in here to nullptr.
	m_pKey = nullptr;

	if (pKey && pKey->IsKey())
	{
		// If so, it's a legitimate key.
		m_pKey = pKey;
		m_holdingKey = true;
	}

	else
	{
		// If not, it's something else. Delete it. We only want the key passed in. 
		delete pKey;
		pKey = nullptr;
	}
}

bool ItemFound::Execute(Player& pPlayer) 
{
	// If full, output message and return.
	if (pPlayer.IsInventoryFull())
	{
		std::cout << "Cannot add items anymore! Inventory full!\n";
		(void)_getch();
		return true;

	}

	// Check if we're holding the key, if not, just add it to the inventory.
	else if (m_holdingKey)
	{
		pPlayer.AddItem(m_pKey);
		m_holdingKey = false;
		(void)_getch();
		return false;
	}

	// Simply add the item.
	pPlayer.AddItem(Item::CreateItem());

	(void)_getch();

	return false;
}

ItemFound::~ItemFound()
{
	if (m_holdingKey)
	{
		delete m_pKey;
		m_pKey = nullptr;
	}
}
