#pragma once
#include<vector>
#include"Creature.h"
#include"Item.h"

using namespace std;


class Monster : public Creature
{
protected :

	vector<Item*> mItem;

public:

	Monster();
	Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore, vector<Item*> item);
	Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore);
	Monster(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore, vector<Item*> item);
	Monster(string creatureName, string creatureDescription, float creatureHealthPoints, vector<Attacks*> attacks, float defenseScore);
	~Monster();

	void CreatureAttacks(Creature* Enemy, Attacks* attacks);
	void CreatureAttacks(Monster* enemy, Attacks* attacks);
	void AddItem(Item* item);
	void RemoveItem(Item* item);
};

