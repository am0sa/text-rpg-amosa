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

	//GET
	inline int GetValue() { return value; }

	//SET
	inline void SetValue() { return value; }

	void Transfer();

private:

};

#endif /* items_h */
