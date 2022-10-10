#include "MagicalWeapons.h"

MagicalWeapons::MagicalWeapons() : Weapon()
{
}

MagicalWeapons::MagicalWeapons(string itemName, string itemDescription, string magicalWeaponName, string magicalWeaponDescription, bool weaponPos, WeaponType type, float weight, float damages, float buyingCost, float durability) : Weapon(itemName, itemDescription, type, weight, damages, buyingCost, durability)
{
	mMagicalWeaponName = magicalWeaponName;
	mMagicalWeaponDescription = magicalWeaponDescription;
	mWeaponPos = weaponPos;
}

string MagicalWeapons::GetMagicalWeaponName()
{
	return mMagicalWeaponName;
}

string MagicalWeapons::GetMagicalWeaponDescription()
{
	return mMagicalWeaponDescription;
}

float MagicalWeapons::GetMagicalWeaponDamages()
{
	return mMagicalWeaponDamages;
}

bool MagicalWeapons::GetWeaponPos()
{
	return mWeaponPos;
}

void MagicalWeapons::SetWeaponPos(bool weaponPos)
{
	mWeaponPos = weaponPos;
}

void MagicalWeapons::SetMagicalWeaponDamages(float magicalWeaponDamages)
{
	mMagicalWeaponDamages = magicalWeaponDamages;
}

void MagicalWeapons::InteractionWeaponPoints(Creature* creature)
{
	if (mWeaponPos)
	{
		creature->SetTotalDamage(creature->GetTotalDamage() + mMagicalWeaponDamages);
	}
	else
	{
		creature->CreatureHeal(mMagicalWeaponDamages);
	}
}
