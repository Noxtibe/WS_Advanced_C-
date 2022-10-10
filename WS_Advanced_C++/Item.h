#pragma once
#include <string>

using namespace std;

class Item
{
public:

	string mItemName;
	string mItemDescription;
	float mItemWeight;
	float mItemBuyingCost;

public:

	Item();
	Item(string itemName, string itemDescription, float itemWeight);
	Item(string itemName, string itemDescription, float itemWeight, float itemBuyingCost);
	~Item();

	string GetItemName();
	string GetItemDescription();
	float GetItemWeight();
	float GetItemBuyingCost();

	void SetItemDescription(string itemDescription);
	void SetItemWeight(float itemWeigth);
	void SetItemBuyingCost(float itemBuyingCost);
};

