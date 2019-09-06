//
//  items.h
//  
//
//  Created by Amosa Osayande on 2019-09-03.
//
#pragma once
#ifndef itemsinput_h
#define itemsinput_h

using namespace std;

#include <string>

class Item
{
public:
	Item() {};
	Item(string input_name, int input_value, bool isKeyItem)
	{
		SetItemName(input_name);
		SetValue(input_value);
		SetKeyItem(isKeyItem);
	}

	int value = 0;
	string itemName = "";
    bool keyItem = false;
	//GET
	inline int GetValue() { return value; }
	inline string GetName() { return itemName; }
    inline bool GetKeyItem() { return keyItem; }
    

	//SET
	inline void SetValue(int input_value) { value = input_value; }
	inline void SetItemName(string input_name) { itemName = input_name; }
    inline void SetKeyItem(bool input_keyItem) { keyItem = input_keyItem; }

	//void Transfer();





};



#endif /* itemsinput_h */
