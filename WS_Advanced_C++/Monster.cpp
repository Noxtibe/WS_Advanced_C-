#include "Monster.h"
#include"Creature.h"
#include<string>
#include<vector>


Monster::Monster() : Creature()
{
}

Monster::Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore, vector<Item*> item) : Creature(creatureName, creatureDescription, creatureHealthPoints, creatureMaxHealthPoints, attacks, defenseScore)
{
	mItem = item;
}

Monster::Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore) : Creature(creatureName, creatureDescription, creatureHealthPoints, defenseScore)
{

}

Monster::Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore, vector<Item*> item) : Creature(creatureName, creatureDescription, creatureHealthPoints, defenseScore)
{
	mItem = item;
}

Monster::Monster(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Attacks*> attacks, float defenseScore) : Creature(creatureName, creatureDescription, creatureHealthPoints, defenseScore)
{
}

Monster::~Monster()
{
}

void Monster::CreatureAttacks(Creature* enemy, Attacks* attacks)
{
	int dice;
	int allDamages = 2;
	int pass = rand() % 20 + 1;
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

void Monster::CreatureAttacks(Monster* enemy, Attacks* attacks)
{
	int dice;
	int allDamages = 2;
	int pass = rand() % 20 + 1;

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
		cout << "2 = " << allDamages << endl;
		enemy->SetCreatureHeatlhPoints(enemy->GetCreatureHealthPoints() - allDamages);

		if (enemy->GetCreatureHealthPoints() <= 0)
		{
			Monster* test = dynamic_cast<Monster*>(enemy);
			if (test != NULL)
			{
				while (!enemy->mItem.empty())
				{
					Item* save = enemy->mItem.back();
					enemy->mItem.pop_back();
					mItem.push_back(save);
				}
			}

			cout << enemy->GetCreatureName() << " is dead.\n";
		}
		else
			cout << "It hits.\n";
	}
	else
		cout << "It misses.\n";
}

void Monster::AddItem(Item* item)
{
	mItem.push_back(item);
	cout << "Add " << item->GetItemName() << " to " << GetCreatureName() << endl;
}

void Monster::RemoveItem(Item* item)
{
	int position = -1;
	for (int i = 0; i < mItem.size(); i++)
	{
		if (mItem[i]->GetItemName() == item->GetItemName())
			position = i;
	}

	if (position >= 0)
	{
		mItem.erase(mItem.begin() + position);
		cout << "Delete " << item->GetItemName() << " from " << GetCreatureName() << endl;
	}
	else
		cout << "Item missing" << endl;
}
