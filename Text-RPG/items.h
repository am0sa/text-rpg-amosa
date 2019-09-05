//
//  items.h
//  
//
//  Created by Amosa Osayande on 2019-09-03.
//

#ifndef items_h
#define items_h

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
	inline void SetValue(int _value) { value = _value; }
    inline bool SetKeyItem(bool _keyItem) { keyItem = _keyItem; }

	void Transfer();

private:

};

#endif /* items_h */
