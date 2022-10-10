#pragma once
#include "Item.h"
#include"IMagicType.h"
#include "MagicTypes.h"
#include "Creature.h"

class MagicalItems : public Item, IMagicType
{
protected :

	string mMagicalItemName;
	string mMagicalItemDescription;
	MagicTypes mMagicTypes;
	float mMagicalDamages;

public :

	MagicalItems();
	MagicalItems(string itemName, string itemDescription, string magicalItemName, string magicalItemDescription, MagicTypes magicTypes, float magicalDamages, float itemWeight, float itemBuyingCost);

	string GetMagicalItemName();
	string GetMagicalItemDescription();
	MagicTypes GetMagicTypes();
	float GetMagicalDamages();

	void SetMagicalDamages(float magicalDamages);
	void MagicEffect(Creature* creature);
};

