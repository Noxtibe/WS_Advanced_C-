#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Inventory
{
private :

	vector<Item> mItemsInventory;

public :

	Inventory();
	Inventory(vector<Item> itemsInventory);
	~Inventory();


	vector<Item> GetItemInventory();
	Item* GetFromInventory();
	Item* GetWeapon();

	void AddItemInventory(Item* item);
	void RemoveItemInventory(Item* item, int indexi);
	void AddItemToInventory();
};

