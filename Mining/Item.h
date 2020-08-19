#pragma once
#include "iItem.h"
#include "ItemTypes.h"

/* Reasoning for this class:

Factory design pattern for creating items. 
																				Class member variables:

1) Reasoning for m_createdKey:

Check in the mine manager if we actually created the key again.


2) Reasoning for m_maxItems:

Get the max in order to decide what item to randomly generate using an algorithm, inside ItemFound.cpp.


3) Reasoning for m_isKey:

Simple boolean so derived classes tell us if they're keys or not.


																				Class functions:

1) Reasoning for constructor:

Initialize whether an item is a key or not. This is needed because key items are needed to get to the next level.


2) Reasoning for CreateItem:

Static function to get items, typical of all factory design patterns.


3) Reasoning for CreatedKey:

Check if we created the key yet in MineManager.cpp.


4) Reasoning for ToggleCreatedKey:

Once we created it, set the boolean to true so it won't happen again for this level.


5) Reasoning for GetMaxItems:

Used in ItemFound.cpp to calculate the range of items when trying to get a random one.


6) Reasoning for GetName:

Show name of item.


7) Reasoning for IsKey:

Confirm if this is the key or not.


8) Reasoning for GetType:

TBA.


9) Reasoning for ShowDescriptionOfItem:

Give the player a description based on the item they have.


8/etc) Reasoning for Execute:

A generic function that will have many polymorphic types so that the appropriate item can have it's own implementation.


																				Class functions (private):

1)


*/

class Item
{
private:
	static bool m_createdKey;
protected:
	bool m_isKey;
public:
	Item(const bool& isKey);
	static Item* CreateItem();
	static bool CreatedKey();
	static void ToggleCreatedKey();
	virtual const char * GetName() const = 0;
	virtual bool IsKey() const = 0;
	virtual Type GetType() const = 0;
	virtual void ShowDescriptionOfItem() const = 0;
	virtual void Execute(iItem item) = 0;
};