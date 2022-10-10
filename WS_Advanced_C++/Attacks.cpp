#include "Attacks.h"
#include"WeaponType.h"
#include"Weapon.h"
#include"DamageTypes.h"

Attacks::Attacks()
{
}

Attacks::Attacks(string label, Weapon* weapon, float damagePoints, DamageTypes type, float bonusAttack)
{
	mLabel = label;
	mWeapon = weapon;
	mDamagePoints = damagePoints;
	mType = type;
	mBonusAttack = bonusAttack;
}

Attacks::~Attacks()
{
}

Weapon* Attacks::GetWeapon()
{
	return mWeapon;
}

string Attacks::GetLabel()
{
	return mLabel;
}

float Attacks::GetDamagePoints()
{
	return mDamagePoints;
}

float Attacks::GetBonusAttacks()
{
	return mBonusAttack;
}

void Attacks::SetWeapon(Weapon* weapon)
{
	mWeapon = weapon;
}

void Attacks::SetDamagePoints(float damagePoints)
{
	mDamagePoints = damagePoints;
}

void Attacks::SetBonusAttack(float bonusAttack)
{
	mBonusAttack = bonusAttack;
}

void Attacks::Resolve()
{

}
