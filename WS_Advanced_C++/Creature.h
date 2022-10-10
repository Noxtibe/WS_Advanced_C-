#pragma once
#include <string>
#include <iostream>
#include <vector>
#include"Attacks.h"

using namespace std;

class Creature
{
public :

	string mCreatureName;
	string mCreatureDescription;
	float mCreatureHealthPoints;
	float mCreatureMaxHealthPoints;
	vector<Attacks*> mAttacks;
	float mDefenseScore;
	int mAllDamages;

public :

	Creature();
	Creature(string creatureName, string creatureDescription, float creatureHealthPoints, float creatureMaxHealthPoints, vector<Attacks*> attacks, float defenseScore);
	Creature(string creatureName, string creatureDescription, float creatureHealthPoints, float defenseScore);

	~Creature();

	string GetCreatureName();
	string GetCreatureDescription();
	float GetCreatureHealthPoints();
	float GetCreatureMaxHealthPoints();
	float GetDefenseScore();
	int GetTotalDamage();

	void SetDefenseScore(float defenseScore);
	void SetDescription(string creatureDescription);
	void SetCreatureHeatlhPoints(float healthPoints);
	void SetTotalDamage(int allDamages);

	void CreatureAttacks(Creature* Enemy, Attacks* attacks);
	void CreatureHeal(float amount);
	void AddAttack(Attacks* attacks);
	void RemoveAttack(Attacks* attacks);
	

	
};