#include <string>
#include <iostream>
#include "Weapon.h"
#include "WeaponType.h"
#include "Item.h"

using namespace std;

Weapon::Weapon() : Item()
{
}

/*Weapon::Weapon(string name, WeaponType type, float weight, float damages, float buyingCost, float durability)
{
	mName = name;
	mType = type;
	mWeight = weight;
	mDamages = damages;
	mBuyingCost = buyingCost;
	mDurability = durability;
}*/

Weapon::Weapon(string itemName, string itemDescription, WeaponType type, float itemWeight, float damages, float buyingCost, float durability) : Item(itemName, itemDescription, itemWeight)
{
	mType = type;
	mDamages = damages;
	mDurability = durability;
}

Weapon::~Weapon()
{
}

float Weapon::GetDamages()
{
	return mDamages;
}

float Weapon::GetDurability()
{
	return mDurability;
}

void Weapon::SetDurability(float durability)
{
	mDurability -= durability;
}

void Weapon::SetDamages(float damages)
{
	mDamages = damages;
}

void Weapon::ToString()
{
	string type;
	switch (mType)
	{
	case Bow:
		type = "Bow";
		break;
	case Dagger:
		type = "Dagger";
		break;
	case Staff:
		type = "Staff";
		break;
	case Sword:
		type = "Sword";
		break;
	case Empty:
		type = "Empty";
		break;
	default:
		type = "";
		break;
	}

	cout << GetItemName() << " a/an " << type << " of " << GetItemWeight() << " kg, can does " << mDamages << "damages, have a buying cost of " << GetItemBuyingCost() << "golds and a durability of " << mDurability * 100 << "%";
}



/*Weapon::~Weapon()
{
}

string Weapon::GetName()
{
	return mName;
}

float Weapon::GetDamages()
{
	return mDamages;
}

float Weapon::GetBuyingCost()
{
	return mBuyingCost;
}

float Weapon::GetDurability()
{
	return mDurability;
}

void Weapon::SetDurability(float durability)
{
	mDurability -= durability;
}

void Weapon::SetDamages(float damages)
{
}

void Weapon::ToString()
{
	string type;
	switch (mType)
	{
	case Bow:
		type = "Bow";
		break;
	case Dagger:
		type = "Dagger";
		break;
	case Staff:
		type = "Staff";
		break;
	case Sword:
		type = "Sword";
		break;
	case Empty:
		type = "Empty";
		break;
	default:
		type = "";
		break;
	}

	cout << mName << " a/an " << type << " of " << mWeight << " kg, can does " << mDamages << "damages, have a buying cost of " << mBuyingCost << "golds and a durability of " << mDurability * 100 << "%";*/
