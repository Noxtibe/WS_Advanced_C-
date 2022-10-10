#include "MagicalWeapons.h"

MagicalWeapons::MagicalWeapons() : Weapon()
{
}

MagicalWeapons::MagicalWeapons(string itemName, string itemDescription, string magicalWeaponName, string magicalWeaponDescription, float magicalDamages, MagicTypes magicTypes, WeaponType type, float weight, float damages, float buyingCost, float durability) : Weapon(itemName, itemDescription, type, weight, damages, buyingCost, durability)
{
	mMagicalWeaponName = magicalWeaponName;
	mMagicalWeaponDescription = magicalWeaponDescription;
	mMagicTypes = magicTypes;
	if (magicalDamages > 0 && magicalDamages <= 5)
		mMagicalWeaponDamages = magicalDamages;
	else
		cout << "Magic damages: " << magicalDamages << " is not between 1 and 5." << endl;
}

MagicalWeapons::~MagicalWeapons()
{
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

MagicTypes MagicalWeapons::GetMagicTypes()
{
	return mMagicTypes;
}

bool MagicalWeapons::IsActive()
{
	return mActive;
}

void MagicalWeapons::SetMagicalTypes(MagicTypes magicTypes)
{
	mMagicTypes = magicTypes;
}

void MagicalWeapons::SetMagicalWeaponDamages(float magicalWeaponDamages)
{
	mMagicalWeaponDamages = magicalWeaponDamages;
}

void MagicalWeapons::MagicEffect(Creature* creature)
{
	creature->SetTotalDamage(creature->GetTotalDamage() + mMagicalWeaponDamages);
	mActive = true;
}

void MagicalWeapons::SetActive(bool active)
{
	mActive = active;
}
