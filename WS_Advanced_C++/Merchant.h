#pragma once
#include <string>
#include <vector>
#include "Weapon.h"


using namespace std;

class Merchant {
private:
	string mMerchantName;
	string mShopName;
	string mMerchantDescription;
	string mMerchantCatchPhrase;
	float mMerchantMoney;
	vector<Weapon*> mInventory;

public:
	Merchant(string merchantName);
	Merchant(string merchantName, string shopName, string shopDescription, string merchantCatchPhrase, float merchantMoney);
	Merchant(string merchantName, string shopName, string shopDescription, string merchantCatchPhrase, float merchantMoney, vector<Weapon*> inventory);

	string GetMerchantName();
	float GetMerchantMoney();
	int GetNbWeapon();
	bool WeaponInInventory(Weapon* weapon);

	void AddMoney(float money);
	void RemoveMoney(float money);
	void AddWeapon(Weapon* weapon);
	void RemoveWeapon(Weapon* weapon);
};