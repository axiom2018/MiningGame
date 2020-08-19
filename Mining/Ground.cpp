#include "Ground.h"
#include "MineImp.h"
#include <iostream>

Ground::Ground(const int& x, const int& y, MineImp* pMineImp) :
	MineAbs(x, y, pMineImp)
{

}

bool Ground::Execute(class Player& pPlayer) const
{
	if (m_pMineImp->Execute(pPlayer))
	{
		return true;
	}

	return false;
}

bool Ground::Draw(const int& x, const int& y) const
{
	if (m_x == x && m_y == y)
	{
		std::cout << k_displayChar << " ";
		return true;
	}

	return false;
}

Ground::~Ground()
{
	delete m_pMineImp;
	m_pMineImp = nullptr;
}
