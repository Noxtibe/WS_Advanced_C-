#include "Merchant.h"
#include <iostream>

Merchant::Merchant(string merchantName)
{
	mMerchantName = merchantName;
	mShopName = "";
	mMerchantDescription = "";
	mMerchantCatchPhrase = "";
	mMerchantMoney = 100;
}

Merchant::Merchant(string merchantName, string shopName, string merchantDescription, string merchantCatchPhrase, float merchantMoney)
{
	mMerchantName = merchantName;
	mShopName = shopName;
	mMerchantDescription = merchantDescription;
	mMerchantCatchPhrase = merchantCatchPhrase;
	mMerchantMoney = merchantMoney;
}

Merchant::Merchant(string merchantName, string shopName, string merchantDescription, string merchantCatchPhrase, float merchantMoney, vector<Weapon*> inventory)
{
	mMerchantName = merchantName;
	mShopName = shopName;
	mMerchantDescription = merchantDescription;
	mMerchantCatchPhrase = merchantCatchPhrase;
	mMerchantMoney = merchantMoney;
	mInventory = inventory;
}

string Merchant::GetMerchantName()
{
	return mMerchantName;
}

float Merchant::GetMerchantMoney()
{
	return mMerchantMoney;
}

size_t Merchant::GetWeapon()
{
	return mInventory.size();
}

bool Merchant::WeaponInInventory(Weapon* weapon)
{
	bool inInventory = false;

	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetItemName() == weapon->GetItemName())
			inInventory = true;
	}

	return inInventory;
}

void Merchant::AddMoney(float merchantMoney)
{
	mMerchantMoney += merchantMoney;
}
void Merchant::RemoveMoney(float merchantMoney)
{
	mMerchantMoney -= merchantMoney;
}
void Merchant::AddWeapon(Weapon* weapon)
{
	mInventory.push_back(weapon);
}
void Merchant::RemoveWeapon(Weapon* weapon)
{
	int position = -1;
	for (int i = 0; i < mInventory.size(); i++)
	{
		if (mInventory[i]->GetItemName() == weapon->GetItemName())
			position = i;
	}

	if (position >= 0)
		mInventory.erase(mInventory.begin() + position);
	else
		cout << "Weapon not found" << endl;
}
