//
//  stocked.h
//  
//
//  Created by Amosa Osayande on 2019-09-03.
//

#ifndef stocked_h
#define stocked_h

#include "items.h"

class Stocked : public Item
{
public:
	Stocked();
	~Stocked();

protected:
	int itemCount;

	//GET
	inline int GetItemCount() { return itemCount; } const

		//SET
		void SetItemCount(int _itemCount) { itemCount = _itemCount; }

	void Transfer();
	void ItemCount();

public:
};

#endif // !stocked_h
