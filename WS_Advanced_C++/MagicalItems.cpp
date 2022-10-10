#include "MagicalItems.h"

MagicalItems::MagicalItems() : Item()
{
	mMagicalItemName = "";
	mMagicalItemDescription = "";
	mMagicalDamages = 0.0f;
}

MagicalItems::MagicalItems(string itemName, string itemDescription, string magicalItemName, string magicalItemDescription, MagicTypes magicTypes, float magicalDamages, float itemWeight, float itemBuyingCost) : Item(itemName, itemDescription, itemWeight, itemBuyingCost)
{
	mMagicalItemName = magicalItemName;
	mMagicalItemDescription = magicalItemDescription;
	mMagicTypes = magicTypes;
	mMagicalDamages = magicalDamages;
}

string MagicalItems::GetMagicalItemName()
{
	return mMagicalItemName;
}

string MagicalItems::GetMagicalItemDescription()
{
	return mMagicalItemDescription;
}

MagicTypes MagicalItems::GetMagicTypes()
{
	return mMagicTypes;
}

float MagicalItems::GetMagicalDamages()
{
	return mMagicalDamages;
}

void MagicalItems::SetMagicalDamages(float magicalDamages)
{
	mMagicalDamages = magicalDamages;
}

void MagicalItems::MagicEffect(Creature* creature)
{
	switch (mMagicTypes)
	{
	case Light:
		creature->CreatureHeal(mMagicalDamages);
		break;
	case Dark:
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicalDamages);
		break;
	case Water:
		creature->SetCreatureMaxHealthPoints(creature->GetCreatureMaxHealthPoints() + mMagicalDamages);
		break;
	case Fire:
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicalDamages);
		break;
	default:
		break;
	}
}
