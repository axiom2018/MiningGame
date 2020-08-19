#pragma once
#include "Item.h"

class Siren : public Item
{
private:
	int m_stepsToDelayEnemies;
public:
	Siren();
	virtual const char* GetName() const override;
	virtual bool IsKey() const override;
	virtual Type GetType() const override;
	virtual void ShowDescriptionOfItem() const override;
	virtual void Execute(iItem item) override;
};

