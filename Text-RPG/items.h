//
//  items.h
//  
//
//  Created by Amosa Osayande on 2019-09-03.
//
#pragma once
#ifndef itemsinput_h
#define itemsinput_h

class Item
{
public:
	Item();
	~Item(); 

protected:
	int value;
    bool keyItem = false;
	//GET
	inline int GetValue() { return value; }
    inline bool GetKeyItem() { return keyItem; }
    

	//SET
	inline void SetValue(int input_value) { value = input_value; }
    inline bool SetKeyItem(bool input_keyItem) { keyItem = input_keyItem; }

	//void Transfer();

private:

};

#endif /* itemsinput_h */
