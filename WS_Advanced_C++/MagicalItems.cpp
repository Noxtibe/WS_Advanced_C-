#include "MagicalItems.h"

MagicalItems::MagicalItems() : Item()
{
}

MagicalItems::MagicalItems(string itemName, string itemDescription, string magicalItemName, string magicalItemDescription, float magicalDamages, bool pos, float itemWeight, float itemBuyingCost) : Item(itemName, itemDescription, itemWeight)
{
	mMagicalItemName = magicalItemName;
	mMagicalItemDescription = magicalItemDescription;
	mMagicalDamages = magicalDamages;
	mPos = pos;
}

string MagicalItems::GetMagicalItemName()
{
	return mMagicalItemName;
}

string MagicalItems::GetMagicalItemDescription()
{
	return mMagicalItemDescription;
}

float MagicalItems::GetMagicalDamages()
{
	return mMagicalDamages;
}

bool MagicalItems::GetPos()
{
	return mPos;
}

void MagicalItems::SetPos(bool pos)
{
	mPos = pos;
}

void MagicalItems::SetMagicalDamages(float magicalDamages)
{
	mMagicalDamages = magicalDamages;
}

void MagicalItems::InteractionPoints(Creature* creature)
{
	if (mPos)
	{
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicalDamages);
	}
	else
	{
		creature->CreatureHeal(mMagicalDamages);
	}
}
