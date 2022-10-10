#include "Creature.h"
#include"Attacks.h"
#include <vector>
#include <iostream>

Creature::Creature()
{

}

Creature::Creature(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore)
{
	mCreatureName = creatureName;
	mCreatureDescription = creatureDescription;
	mCreatureHealthPoints = creatureHealthPoints;
	mCreatureMaxHealthPoints = creatureHealthPoints;
	mAttacks = attacks;
	if (defenseScore > 0 && defenseScore <= 20)
		mDefenseScore = defenseScore;
	else
		cout << defenseScore << " FAILED !\n";
	
}

Creature::Creature(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore)
{
	mCreatureName = creatureName;
	mCreatureDescription = creatureDescription;
	mCreatureHealthPoints = creatureHealthPoints;
	if (defenseScore > 0 && defenseScore <= 20)
		mDefenseScore = defenseScore;
	else
		cout << defenseScore << " FAILED !\n";
}

Creature::Creature(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Item*> inventory, float defenseScore)
{
	mCreatureName = creatureName;
	mCreatureDescription = creatureDescription;
	mCreatureHealthPoints = creatureHealthPoints;
	mCreatureMaxHealthPoints = creatureHealthPoints;
	mInventory = inventory;
	if (defenseScore > 0 && defenseScore <= 20)
		mDefenseScore = defenseScore;
	else
		cout << defenseScore << " FAILED !\n";
}

Creature::Creature(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Attacks*> attacks, vector<Item*> inventory, float defenseScore)
{
	mCreatureName = creatureName;
	mCreatureDescription = creatureDescription;
	mCreatureHealthPoints = creatureHealthPoints;
	mCreatureMaxHealthPoints = creatureHealthPoints;
	mAttacks = attacks;
	mInventory = inventory;
	if (defenseScore > 0 && defenseScore <= 20)
		mDefenseScore = defenseScore;
	else
		cout << defenseScore << " FAILED !\n";
}

Creature::~Creature()
{
}

string Creature::GetCreatureName()
{
	return mCreatureName;
}

string Creature::GetCreatureDescription()
{
	return mCreatureDescription;
}

float Creature::GetCreatureHealthPoints()
{
	return mCreatureHealthPoints;
}

float Creature::GetCreatureMaxHealthPoints()
{
	return mCreatureMaxHealthPoints;
}

float Creature::GetDefenseScore()
{
	return mDefenseScore;
}

int Creature::GetTotalDamage()
{
	return mAllDamages;
}

vector<Item*> Creature::GetInventory()
{
	return mInventory;
}

size_t Creature::GetLoot()
{
	return mInventory.size();
}

void Creature::SetDefenseScore(float defenseScore)
{
	mDefenseScore -= defenseScore;
}

void Creature::SetCreatureDescription(string creatureDescription)
{
	mCreatureDescription = creatureDescription;
}

void Creature::SetCreatureHeatlhPoints(float healthPoints)
{
	mCreatureHealthPoints = healthPoints;
}

void Creature::SetCreatureMaxHealthPoints(float creatureMaxHealthPoints)
{
	mCreatureMaxHealthPoints = creatureMaxHealthPoints;
}

void Creature::SetTotalDamage(int allDamages)
{
	mAllDamages = allDamages;
}

void Creature::CreatureAttacks(Creature* enemy, Attacks* attacks)
{
	int dice;
	int pass = rand() % 20 + 1;
	int allDamages = 2;

	pass += attacks->GetBonusAttacks();
	if (pass >= enemy->GetDefenseScore())
	{
		cout << "Damages : ";
		for (int i = 0; i < 3; i++)
		{
			dice = rand() % 6 + 1;
			allDamages += dice;
			cout << dice << " + ";
		}
		cout << " 2 = " << allDamages << endl;
		enemy->mCreatureHealthPoints -= allDamages;

		if (enemy->mCreatureHealthPoints <= 0)
		{
			cout << enemy->GetCreatureName() << " the creature is dead.\n";
		}
		else
			cout << "It hits this thing !\n";
	}
	else
		cout << "Ouuupsss...\n";
}

void Creature::CreatureHeal(float amount)
{
	if (mCreatureHealthPoints == mCreatureMaxHealthPoints)
	{
		cout << "Maximum health reached !\n";
	}
	else
	{
		mCreatureHealthPoints += amount;
		if (mCreatureHealthPoints > mCreatureMaxHealthPoints)
		{
			mCreatureHealthPoints = mCreatureMaxHealthPoints;
		}
		cout << "HEEEEEAAAAAAAAAALLLLLLL.\n";
	}
}

void Creature::AddAttack(Attacks* attacks)
{
	mAttacks.push_back(attacks);
	cout << mCreatureName << " has learned a new attack: " << attacks->GetLabel() << endl;
}

void Creature::RemoveAttack(Attacks* attacks)
{
	int position = -1;
	for (int i = 0; i < mAttacks.size(); i++)
	{
		if (mAttacks[i]->GetLabel() == attacks->GetLabel())
			position = i;
	}

	if (position >= 0)
		mAttacks.erase(mAttacks.begin() + position);
	else
		cout << "Missing attack..." << endl;
}

void Creature::AddItem(Item* item)
{
	mInventory.push_back(item);
	cout << "Got a new item " << item->GetItemName() << " to " << GetCreatureName() << endl;
}

void Creature::RemoveItem(Item* item)
{
	int position = -1;
	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetItemName() == item->GetItemName())
			position = i;
	}

	if (position >= 0)
	{
		mInventory.erase(mInventory.begin() + position);
		cout << "Delete " << item->GetItemName() << " from " << GetCreatureName() << endl;
	}
	else
		cout << "Missing item..." << endl;
}

// BASE ATTACKS

/*void Creature::CreatureAttacks(Creature* enemy, Attacks* attacks)
{
	int pass = rand() % 20 + 1;
	pass += attacks->GetBonusAttacks();
	if (pass >= enemy->GetDefenseScore())
	{
		enemy->mCreatureHealthPoints -= attacks->GetDamagePoints();
		if (enemy->mCreatureHealthPoints <= 0)
		{
			cout << enemy->GetCreatureName() << " the creature is dead.\n";
		}
		else
		{
			cout << "End of the carnage.\n";
		}
	}
}*/

// RANDOMIZE ATTACKS
