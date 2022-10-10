#pragma once
#include "Weapon.h"
#include"IMagicType.h"
#include "Creature.h"

class MagicalWeapons : public Weapon, IMagicType
{
protected:

	string mMagicalWeaponName;
	string mMagicalWeaponDescription;
	float mMagicalWeaponDamages;
	bool mWeaponPos;

public:

	MagicalWeapons();
	MagicalWeapons(string itemName, string itemDescription, string magicalWeaponName, string magicalWeaponDescription, bool weaponPos, WeaponType type, float weight, float damages, float buyingCost, float durability);

	string GetMagicalWeaponName();
	string GetMagicalWeaponDescription();
	float GetMagicalWeaponDamages();
	bool GetWeaponPos();

	void SetWeaponPos(bool weaponPos);
	void SetMagicalWeaponDamages(float magicalWeaponDamages);
	void InteractionWeaponPoints(Creature* creature);
};

