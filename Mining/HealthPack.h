#pragma once
#include "Item.h"

class HealthPack : public Item
{
private:
	static const int k_amountToHeal = 30;
public:
	HealthPack();
	virtual const char * GetName() const override;
	virtual bool IsKey() const override;
	virtual Type GetType() const override;
	virtual void ShowDescriptionOfItem() const override;
	virtual void Execute(iItem item) override;
};

