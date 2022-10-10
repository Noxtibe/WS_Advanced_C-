#pragma once
#include "Item.h"
#include"IMagicType.h"
#include "Creature.h"

class MagicalItems : public Item, IMagicType
{
protected :

	string mMagicalItemName;
	string mMagicalItemDescription;
	float mMagicalDamages;
	bool mPos;

public :

	MagicalItems();
	MagicalItems(string itemName, string itemDescription, string magicalItemName, string magicalItemDescription, float magicalDamages, bool pos, float itemWeight, float itemBuyingCost);

	string GetMagicalItemName();
	string GetMagicalItemDescription();
	float GetMagicalDamages();
	bool GetPos();

	void SetPos(bool pos);
	void SetMagicalDamages(float magicalDamages);
	void InteractionPoints(Creature* creature);
};

