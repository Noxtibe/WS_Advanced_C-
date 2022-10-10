#pragma once
#include <string>
#include "WeaponType.h"
#include "Item.h"

using namespace std;

class Weapon : public Item 
{
protected:

	WeaponType mType;
	float mDamages;
	float mDurability;

public:

	Weapon();
	//Weapon(string name, WeaponType type, float weight, float damages, float buyingCost, float durability);
	Weapon(string name, string itemDescription, WeaponType type, float weight, float damages, float buyingCost, float durability);
	~Weapon();

	float GetDamages();
	float GetDurability();

	void SetDurability(float durability);
	void SetDamages(float damages);
	void ToString();
};

// Before Interface

/*protected:

	string mName;
	WeaponType mType;
	float mWeight;
	float mDamages;
	float mBuyingCost;
	float mDurability;

public:

	Weapon();
	Weapon(string name, WeaponType type, float weight, float damages, float buyingCost, float durability);
	~Weapon();

	string GetName();
	float GetDamages();
	float GetBuyingCost();
	float GetDurability();

	void SetDurability(float durability);
	void ToString();*/