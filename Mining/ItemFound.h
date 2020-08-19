#pragma once
#include "MineImp.h"

// Concrete implementation. 

class ItemFound : public MineImp
{
private:
	class Item* m_pKey;
	bool m_holdingKey;
public:
	ItemFound(class Item * pKey = nullptr);
	virtual bool Execute(class Player& pPlayer) override;
	~ItemFound();
};

