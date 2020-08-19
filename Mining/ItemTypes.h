#pragma once

/* Reasoning for this enum:

When we use the variant inside of the SelectItem function inside of Inventory, we do so in order to set any data the item will need to do its job, great.
But the health pack requires the players health address. What if we had an item to affect the enemies? Or bomb damage? We'd need to basically understand
the PURPOSE so inside Inventory.cpp we can assign the appropriate thing.

*/

enum class Type
{
	Key,
	Health,
	Siren,
};