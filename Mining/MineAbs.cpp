#include "MineAbs.h"
#include "MineImp.h"

MineAbs::MineAbs(const int& x, const int& y, MineImp* pMineImp)
{
	m_x = x;
	m_y = y;
	m_pMineImp = pMineImp;
}

int MineAbs::GetX() const
{
	return m_x;
}

int MineAbs::GetY() const
{
	return m_y;
}

void MineAbs::ResetPosition(const int& x, const int& y)
{
	m_x = x;
	m_y = y;
}