#pragma once
#include <variant>
#include <string>

/* Reasoning for this struct:

This struct will contain the C++ 17 std::variant type to be used in the item system. More specifically the Item.h interface will have a 
pure virtual function that takes the struct in. Putting the literal variant as the argument will force us to change every single place
where that varient is declared or exists in code. So that's why we use the struct. We'll only have to change ONE place.

*/

struct iItem
{
	std::variant<int*, class EnemyManager*, class Gate*> m_var;
};
