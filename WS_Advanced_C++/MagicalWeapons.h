#pragma once
#include "Weapon.h"
#include"IMagicType.h"
#include "MagicTypes.h"
#include "Creature.h"

class MagicalWeapons : public Weapon, IMagicType
{
protected:

	string mMagicalWeaponName;
	string mMagicalWeaponDescription;
	float mMagicalWeaponDamages;
	MagicTypes mMagicTypes;
	bool mActive = false;

public:

	MagicalWeapons();
	MagicalWeapons(string itemName, string itemDescription, string magicalWeaponName, string magicalWeaponDescription, float magicalDamages, MagicTypes magicTypes, WeaponType type, float weight, float damages, float buyingCost, float durability);
	~MagicalWeapons();

	string GetMagicalWeaponName();
	string GetMagicalWeaponDescription();
	float GetMagicalWeaponDamages();
	MagicTypes GetMagicTypes();
	bool IsActive();

	void SetMagicalTypes(MagicTypes magicTypes);
	void SetMagicalWeaponDamages(float magicalWeaponDamages);
	void MagicEffect(Creature* creature);
	void SetActive(bool active);
};

