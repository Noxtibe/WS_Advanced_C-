#pragma once
#include <string>
#include <iostream>
#include <vector>
#include"WeaponType.h"
#include"Weapon.h"
#include"DamageTypes.h"

using namespace std;

class Attacks
{
protected:

	string mLabel;
	Weapon* mWeapon;
	float mDamagePoints;
	DamageTypes mType;
	float mBonusAttack;

public :

	Attacks();
	Attacks(string label, Weapon* weapon, float damagePoints, DamageTypes type, float bonusAttack);
	~Attacks();

	Weapon* GetWeapon();
	string GetLabel();
	float GetDamagePoints();
	float GetBonusAttacks();

	void SetWeapon(Weapon* weapon);
	void SetDamagePoints(float damagePoints);
	void SetBonusAttack(float bonusAttack);


	void Resolve();
};

