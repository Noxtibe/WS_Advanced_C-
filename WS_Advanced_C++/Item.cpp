#include "Item.h"

Item::Item()
{
	mItemName = "";
	mItemDescription = "";
	mItemWeight = 0;
	mItemBuyingCost = 0;
}

Item::Item(string itemName, string itemDescription, float itemWeight)
{
	mItemName = itemName;
	mItemDescription = itemDescription;
	mItemWeight = itemWeight;
}

Item::Item(string itemName, string itemDescription, float itemWeight, float itemBuyingCost)
{
	mItemName = itemName;
	mItemDescription = itemDescription;
	mItemWeight = itemWeight;
	mItemBuyingCost = itemBuyingCost;
}

Item::~Item()
{
}

string Item::GetItemName()
{
	return mItemName;
}

string Item::GetItemDescription()
{
	return mItemDescription;
}

float Item::GetItemWeight()
{
	return mItemWeight;
}

float Item::GetItemBuyingCost()
{
	return mItemBuyingCost;
}

void Item::SetItemDescription(string itemDescription)
{
	mItemDescription = itemDescription;
}

void Item::SetItemWeight(float itemWeight)
{
	mItemWeight = itemWeight;
}

void Item::SetItemBuyingCost(float itemBuyingCost)
{
	mItemBuyingCost = itemBuyingCost;
}

