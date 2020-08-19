#pragma once
#include "MineImp.h"

// Concrete implementation.

class Bomb : public MineImp
{
public:
	virtual bool Execute(class Player& pPlayer) override;
	~Bomb();
};

