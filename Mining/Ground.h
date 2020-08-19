#pragma once
#include "MineAbs.h"

// Refined abstraction.

class Ground : public MineAbs
{
public:
	Ground(const int& x, const int& y, class MineImp* pMineImp);
	virtual bool Execute(class Player& pPlayer) const override;
	virtual bool Draw(const int& x, const int& y) const override;
	~Ground();
};

