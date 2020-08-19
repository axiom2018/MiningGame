#include "Inventory.h"
#include "Item.h"
#include "iItem.h"
#include "EnemyManager.h"
#include "Gate.h"
#include <iostream>
#include <conio.h>

Inventory::Inventory(int* pPlayerHealth, Gate * pGate)
{
	// Initialize variables.
	m_currentSize = 0;
	m_foundKey = false;

	// Save the variables that will be needed for the items.
	m_pPlayerHealth = pPlayerHealth;
	m_pGate = pGate;

	// Index will be needed to indicate what item we're CURRENTLY looking at.
	m_index = 0;
}

void Inventory::Instructions() const
{
	std::cout << "\n\nw/s - move up and down. a - select an item. q - exit inventory screen.\n";
	std::cout << "Inventory size: " << m_currentSize << "\n";
	std::cout << "MAX inventory space: " << k_maxSize << "\n";
}

bool Inventory::GetInput() 
{
	// Get input from player.
	char input = _getch();

	switch (input)
	{
	case 'w':
		MoveUp();
		break;
	case 's':
		MoveDown();
		break;
	case 'a':
		SelectItem();
		break;
	case 'q':
		return true;
	default:
		break;
	}

	return false;
}

void Inventory::MoveUp()
{
	// Get index size of the inventory.
	int size = m_pItems.size() - 1;

	// Use the next desired position.
	int desiredIndex = m_index - 1;

	// Check if desired index is less than the minimum size of the inventory.
	if (desiredIndex < 0)
	{
		// If so, return.
		std::cout << "Can't go higher!\n";
		return;
	}

	// If not, decrement.
	m_index = desiredIndex;
}

void Inventory::MoveDown()
{
	// Get index size of the inventory.
	int size = m_pItems.size() - 1;

	// Use the next desired position.
	int desiredIndex = m_index + 1;

	// Check if desired index is greater than the total size of the inventory.
	if (desiredIndex > size)
	{
		// If so, return.
		std::cout << "Can't go lower!\n";
		return;
	}

	// If not, increment.
	m_index = desiredIndex;
}

void Inventory::SelectItem()
{
	// First get the item.
	Item* pSelectedItem = m_pItems.at(m_index);

	// Get the varient structure ready.
	iItem item;

	// Now see what type of item it is so we know what data to assign to it.
	switch (pSelectedItem->GetType())
	{
	case Type::Key:
		std::cout << "Press the U/u key when you have reached the gates coordinates to unlock the gate!\n";
		return;
	case Type::Health:
		item.m_var = m_pPlayerHealth;
		break;
	case Type::Siren:
		item.m_var = &EnemyManager::Get();
		break;
	default:
		break;
	}

	// Send varient to the item.
	pSelectedItem->Execute(item);

	// Now to get rid of the item from our inventory.
	m_pItems.erase(m_pItems.begin() + m_index);

	// Then delete it.
	delete pSelectedItem;
	pSelectedItem = nullptr;

	// Since we used an item, let's reset the index to be the top.
	m_index = 0;

	// Decrement inventory size.
	--m_currentSize;
}

void Inventory::AddItem(Item* pItem)
{
	// Check if max is reached.
	if (m_currentSize >= k_maxSize)
	{
		std::cout << "Inventory full! Use items or toss them to make room!\n";
		(void)_getch();
		return;
	}

	/* This small system will help the entire next level system. the player advances a level if they have a key. So we check here if the item
	we're receiving is a key. If so, we'll set a boolean to true. When the player moves to the gate to the next level, we'll call the player
	to check if they have a key and they'll call the inventory class and INSTEAD of doing an o(n) operation where we cycle through the inventory
	we'll return if the boolean is true or false. */
	if (pItem->IsKey())
	{
		m_foundKey = true;
	}

	std::cout << "Found " << pItem->GetName() << "!\n";
	m_pItems.push_back(pItem);
	++m_currentSize;
}

void Inventory::OpenInventoryScreen()
{
	// Check if inventory empty, if so, just don't bother opening it.
	if (m_pItems.empty())
	{
		std::cout << "Inventory empty!\n";
		(void)_getch();
		return;
	}

	// Clear the screen of the grid.
	system("cls");

	// Then this symbol will be used to mark the item the player is about to select.
	char symbolForIndex = 'x';

	// Loop over the items.
	while (true)
	{
		std::cout << "++++++++++			Inventory			++++++++++\n\n";
		std::cout << "Items:\n\n";

		// If we do have items in here even after using some, show them.
		if (!m_pItems.empty())
		{
			for (unsigned int i = 0; i < m_pItems.size(); ++i)
			{
				if (i == m_index)
				{
					std::cout << i + 1 << ") " << m_pItems[i]->GetName() << " [" << symbolForIndex << "]\n";
				}

				else
				{
					std::cout << i + 1 << ") " << m_pItems[i]->GetName() << " [ ]\n";
				}

				// show the description of the item.
				m_pItems[i]->ShowDescriptionOfItem();
			}
		}

		// If no items, tell the player.
		else
		{
			std::cout << "No items left!\n";
		}

		// Show the keys to press in the inventory menu so they can use it properly.
		Instructions();

		// Show the health, we have health packs so it'll be good to see the health upgrade right in the inventory.
		std::cout << "Player health: " << *m_pPlayerHealth << "\n";

		if (GetInput())
		{
			// If true, we're exiting the menu but let's reset the index so when we enter again, it shows at first item in vector.
			m_index = 0;
			system("cls");
			break;
		}

		system("cls");
	}
}

bool Inventory::UseKey(const int& playerX, const int& playerY)
{
	// If boolean is false, we haven't found the key!
	if (!m_foundKey)
	{
		std::cout << "Haven't found the key yet!\n";
		(void)_getch();
		return false;
	}

	// Now if we have found the key, but we're not at the right position yet?
	else if (m_pGate->GetX() != playerX || m_pGate->GetY() != playerY)
	{
		std::cout << "You found the key but you're not AT the gate!\n";
		(void)_getch();
		return false;
	}

	// We know it's in the inventory, find it.
	for (unsigned int i = 0; i < m_pItems.size(); ++i)
	{
		if (m_pItems.at(i)->IsKey())
		{
			// Get the varient structure ready.
			iItem item;

			// Set the gate.
			item.m_var = m_pGate;

			// Run the execute function and let the key.cpp implementation do the rest.
			m_pItems.at(i)->Execute(item);

			// Now to get rid of the item from our inventory.
			Item* pKey = m_pItems.at(i);

			// Delete it since we're done with it.
			delete pKey;
			pKey = nullptr;

			// Get it out of the vector since we just deleted the key.
			m_pItems.erase(m_pItems.begin() + i);

			// Decrement because we just got rid of an item.
			--m_currentSize;

			// At this point we're at the right location AND we have the key, so set to false.
			m_foundKey = false;

			return true;
		}
	}

	return false;
}

bool Inventory::IsFull() const
{
	// Check if max is reached.
	if (m_currentSize >= k_maxSize)
	{
		return true;
	}

	return false;
}

Inventory::~Inventory()
{
	for (unsigned int i = 0; i < m_pItems.size(); ++i)
	{
		delete m_pItems.at(i);
		m_pItems.at(i) = nullptr;
	}
}
