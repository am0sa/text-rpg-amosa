//
//  stocked.h
//  
//
//  Created by Amosa Osayande on 2019-09-03.
//
#pragma once

#ifndef stocked_h
#define stocked_h

#include "items.h"

#include <vector>

class Stocked : public Item
{
public:
	Stocked();
	~Stocked();

public:
	vector<Item> stock;

	//GET

	//SET
	inline void AddItem(Item input_item, vector<Item> &stock) { stock.push_back(input_item); }

	//void Transfer();
	//void ItemCount();

public:
};

#endif // !stocked_h
