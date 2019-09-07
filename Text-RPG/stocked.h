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
	std::vector<Item> stock;

	Stocked() {};
	
	Stocked(vector<Item> input_stock)
	{
		stock = input_stock;
	}


	//GET

	//SET
	inline void AddItem(Item input_item, std::vector<Item> &item) { item.push_back(input_item); }

};

#endif // !stocked_h
