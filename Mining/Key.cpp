#include "Key.h"
#include "Gate.h"
#include <iostream>
#include <conio.h>

Key::Key() :
	Item(true)
{

}

const char * Key::GetName() const
{
	return "Key";
}

bool Key::IsKey() const
{
	return true;
}

Type Key::GetType() const
{
	return Type::Key;
}

void Key::ShowDescriptionOfItem() const
{
	std::cout << "     The key to open the gate, does nothing. Just hold it when you get to the gate to get through.\n";
}

void Key::Execute(iItem item)
{
	// We'll do one check to make SURE this is the right type we need in here.
	if (auto value = std::get_if<class Gate*>(&item.m_var))
	{
		// Get the gate.
		Gate* pGate = *value;

		// Unlock it.
		pGate->ReachedGate();

		std::cout << "Gate is now unlocked!\n";
		(void)_getch();
	}
}
