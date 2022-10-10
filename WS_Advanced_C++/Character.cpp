#include <string>
#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Creature.h"
#include"Attacks.h"


using namespace std;

Character::Character() : Creature()
{
	mCatchPhrase = "";
	mMoney = 0;
	mWeapon = nullptr;
	mRace = Human;
}

Character::Character(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore, string lastName, string catchPhrase, float money, Race race, CharacterClass characterClass) : Creature(creatureName, creatureDescription, creatureHealthPoints, creatureMaxHealthPoints, attacks, defenseScore)
{
	/*mCreatureName = creatureName;
	mCreatureDescription = creatureDescription;
	mCreatureHealthPoints = creatureHealthPoints;
	mCreatureMaxHealthPoints = creatureHealthPoints;
	mAttacks = attacks;
	mDefenseScore = defenseScore;*/
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mRace = race;
	mCharacterClass = characterClass;
}

Character::Character(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore, string lastName, string catchPhrase, float money, Weapon* weapon, Race race, CharacterClass characterClass) : Creature(creatureName, creatureDescription, creatureHealthPoints, defenseScore)
{
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mWeapon = weapon;
	mRace = race;
	mCharacterClass = characterClass;
}

/*Character::Character(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Attacks*> attacks, float defenseScore, string lastName, string catchPhrase, float money, Weapon* weapon, Race race, CharacterClass characterClass) : Creature(creatureName, creatureDescription, creatureHealthPoints, attacks, defenseScore)
{
	mLastName = lastName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mWeapon = weapon;
	mRace = race;
	mCharacterClass = characterClass;
}*/

Character::~Character()
{
}

float Character::GetMoney()
{
	return mMoney;
}

Weapon* Character::GetWeapon()
{
	return mWeapon;
}

void Character::AddMoney(float money)
{
	mMoney += money;
}

void Character::RemoveMoney(float money)
{
	mMoney -= money;
}

void Character::SetWeapon(Weapon* newWeapon)
{
	mWeapon = newWeapon;
}

void Character::Introduce()
{
	string race;
	string characterClass;
	switch (mRace)
	{
	case Elf:
		race = "Elf";
		break;
	case Orc:
		race = "Orc";
		break;
	case Gobelin:
		race = "Gobelin";
		break;
	case Human:
		race = "Human";
		break;
	case Dwarf:
		race = "Dwarf";
		break;
	default:
		race = "";
		break;
	}
	switch (mCharacterClass)
	{
	case Archer:
		characterClass = "Archer";
		break;
	case Warrior:
		characterClass = "Warrior";
		break;
	case Priest:
		characterClass = "Priest";
		break;
	case Paladin:
		characterClass = "Paladin";
		break;
	case Less:
		characterClass = "Less";
		break;
	default:
		characterClass = "";
		break;
	}

	cout << mCatchPhrase << " I'm " << mCreatureName << " " << mLastName << " a/an " << race << " " << characterClass << " class " << endl;
	cout << "I possess ";
	if(mWeapon != nullptr)
	{
		mWeapon->ToString();
		cout << " and ";
	}
	cout << mMoney << " money" << endl;
}

void Character::Buy(Weapon* weapon, Merchant* merchant)
{
	if (merchant->WeaponInInventory(weapon))
	{
		float finalCost = weapon->GetItemBuyingCost() * (1 + weapon->GetDamages());
		if ((mMoney - finalCost) >= 0)
		{
			RemoveMoney(finalCost);
			merchant->AddMoney(finalCost);
			SetWeapon(weapon);
			merchant->RemoveWeapon(weapon);
			cout << mCreatureName << " has buy a new weapon.\n";
		}
		else
			cout << mCreatureName << " can't buy this weapon." << endl;
	}
	else
		cout << weapon->GetItemName() << " can't buy from " << merchant->GetMerchantName() << ".\n";
}

void Character::Sell(Merchant* merchant)
{
	if (mWeapon != nullptr) {
		float finalCost = GetWeapon()->GetItemBuyingCost() / (1 - GetWeapon()->GetDamages());
		if ((merchant->GetMerchantMoney() - finalCost) >= 0)
		{
			merchant->RemoveMoney(finalCost);
			AddMoney(finalCost);
			merchant->AddWeapon(mWeapon);
			SetWeapon(nullptr);
			cout << mCreatureName << " has sell his weapon.\n";
		}
		else
			cout << merchant->GetMerchantName() << " can't buy your weapon." << endl;
	}
	else
		cout << mCreatureName << " doesn't have weapon." << endl;
}

uint8_t Character::GetRace()
{
	return mRace;
}




// Before the modifications for creature



/*Character::Character(string firstName, string lastName)
{
	mCreatureName = firstName;
	mLastName = lastName;
	mCatchphrase = "";
	mMoney = 0;
	mCreatureHealthPoints = 100;
	mWeapon = nullptr;
	mRace = Human;
	mCharacterClass = CharacterClass::Less;
}

Character::Character(string firstName, string lastName, string catchphrase, float money, float lifePoints, Race race, CharacterClass characterClass)
{
	mCreatureName = firstName;
	mLastName = lastName;
	mCatchphrase = catchphrase;
	mMoney = money;
	mCreatureHealthPoints = lifePoints;
	mWeapon = nullptr;
	mRace = race;
	mCharacterClass = characterClass;
}

Character::Character(string firstName, string lastName, string catchphrase, float money, float lifePoints, Weapon& weapon, Race race, CharacterClass characterClass)
{
	mCreatureName = firstName;
	mLastName = lastName;
	mCatchphrase = catchphrase;
	mMoney = money;
	mCreatureHealthPoints = lifePoints;
	mWeapon = &weapon;
	mRace = race;
	mCharacterClass = characterClass;
}

Character::~Character()
{
}

float Character::GetMoney()
{
	return mMoney;
}

Weapon* Character::GetWeapon()
{
	return mWeapon;
}

void Character::AddMoney(float money)
{
	mMoney += money;
}

void Character::RemoveMoney(float money)
{
	mMoney -= money;
}

void Character::SetWeapon(Weapon* newWeapon)
{
	mWeapon = newWeapon;
}

void Character::Introduce()
{
	string race;
	string characterClass;
	switch (mRace)
	{
	case Elf:
		race = "Elf";
		break;
	case Orc:
		race = "Orc";
		break;
	case Gobelin:
		race = "Gobelin";
		break;
	case Human:
		race = "Human";
		break;
	case Dwarf:
		race = "Dwarf";
		break;
	default:
		race = "";
		break;
	}
	switch (mCharacterClass)
	{
	case Archer:
		characterClass = "Archer";
		break;
	case Warrior:
		characterClass = "Warrior";
		break;
	case Priest:
		characterClass = "Priest";
		break;
	case Paladin:
		characterClass = "Paladin";
		break;
	case Less:
		characterClass = "Less";
		break;
	default:
		characterClass = "";
		break;
	}

	cout << mCatchphrase << " I'm " << mCreatureName << " " << mLastName << " a/an " << race << " " << characterClass << " class " << endl;
	cout << "I have ";
	if(mWeapon != nullptr)
	{
		mWeapon->ToString();
		cout << " and ";
	}
	cout << mMoney << " golds." << endl;
}

void Character::Buy(Weapon* weapon, Merchant* merchant)
{
	if (merchant->WeaponInInventory(weapon))
	{
		float finalCost = weapon->GetBuyingCost() * (1 + weapon->GetDamages());
		if ((mMoney - finalCost) >= 0)
		{
			RemoveMoney(finalCost);
			merchant->AddMoney(finalCost);
			SetWeapon(weapon);
			merchant->RemoveWeapon(weapon);
			cout << mCreatureName << " has buy a new weapon.\n";
		}
		else
			cout << mCreatureName << " can't buy this weapon." << endl;
	}
	else
		cout << weapon->GetName() << " can't buy from " << merchant->GetName() << ".\n";
}

void Character::Sell(Merchant* merchant)
{
	if (mWeapon != nullptr) {
		float finalCost = GetWeapon()->GetBuyingCost() / (1 - GetWeapon()->GetDamages());
		if ((merchant->GetMoney() - finalCost) >= 0)
		{
			merchant->RemoveMoney(finalCost);
			AddMoney(finalCost);
			merchant->AddWeapon(mWeapon);
			SetWeapon(nullptr);
			cout << mCreatureName << " has sell his weapon.\n";
		}
		else
			cout << merchant->GetName() << " can't buy your weapon." << endl;
	}
	else
		cout << mCreatureName << " doesn't have weapon." << endl;
}

void Character::UseWeapon(Weapon* weapon, Character* targetCharacter)
{
	string answer;
	if (targetCharacter->mCreatureHealthPoints > 0) 
	{
		if (weapon->GetDurability() > 0) {
			targetCharacter->mCreatureHealthPoints -= weapon->GetDamages();
			weapon->SetDurability(0.01f);

			cout << targetCharacter->mCreatureHealthPoints << endl;
			if (targetCharacter->mCreatureHealthPoints <= 0)
			{
				do
				{
					cout << "Loot " << targetCharacter->mCreatureName << " " << targetCharacter->mLastName << " ?(y/n)" << endl;
					cin >> answer;
				} while (answer != "y" && answer != "n");
				if (answer == "y")
				{
					AddMoney(targetCharacter->GetMoney());
					if (targetCharacter->mWeapon != NULL)
						SetWeapon(targetCharacter->mWeapon);
				}
			}
		}
		else
		{
			cout << weapon->GetName() << " is broken." << endl;
		}
	}
	*/
