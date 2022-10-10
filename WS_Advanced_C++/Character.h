#pragma once
#include "WeaponType.h"
#include "Weapon.h"
#include "Race.h"
#include "CharacterClass.h"
#include <string>
#include "Merchant.h"
#include "Creature.h"

using namespace std;

class Character : public Creature
{
private:

	string mLastName;
	string mCatchPhrase;
	float mMoney;
	Weapon* mWeapon;
	Race mRace;
	CharacterClass mCharacterClass;

public:

	Character();
	Character(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore, string lastName, string catchPhrase, float money, Race race, CharacterClass characterClass);
	Character(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore, string lastName, string catchPhrase, float money, Weapon* weapon, Race race, CharacterClass characterClass);
	Character(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Attacks*> attacks, float defenseScore, string lastName, string catchPhrase, float money, Weapon* weapon, Race race, CharacterClass characterClass);
	~Character();

	float GetMoney();
	Weapon* GetWeapon();
	void AddMoney(float money);
	void RemoveMoney(float money);
	void SetWeapon(Weapon* newWeapon);

	void Introduce();
	void Buy(Weapon* weapon, Merchant* merchant);
	void Sell(Merchant* merchant);
};


// Before the modifications for creature

/*private:

	string mFirstName;
	string mLastName;
	string mCatchphrase;
	float mMoney;
	float mLifePoints;
	Weapon* mWeapon;
	Race mRace;
	CharacterClass mCharacterClass;

public:

	Character(string firstName, string lastName);
	Character(string firstName, string lastName, string catchphrase, float money, float lifePoints, Race race, CharacterClass characterClass);
	Character(string firstName, string lastName, string catchphrase, float money, float lifePoints, Weapon &weapon, Race race, CharacterClass characterClass);
	~Character();

	float GetMoney();
	Weapon* GetWeapon();
	void AddMoney(float money);
	void RemoveMoney(float money);
	void SetWeapon(Weapon* newWeapon);

	void Introduce();
	void Buy(Weapon* weapon, Merchant* merchant);
	void Sell(Merchant* merchant);
	void UseWeapon(Weapon* weapon, Character* targetCharacter);
	*/