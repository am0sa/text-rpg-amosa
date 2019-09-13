#pragma once

#ifndef beinginput_h
#define beinginput_h

#include "stocked.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Being : public Stocked
{
public:
	Being() {};
	Being(string input_name, int input_health, int input_speed, int input_luck, int input_strength) 
	{
		SetName(input_name);
		SetHealth(input_health);
		SetSpeed(input_speed);
		SetStrength(input_strength);
	}
	~Being() {};

	string name = "";
	int health = 0;
	int speed = 0;
	int luck = 0;
	int strength = 0; 

	//GET
	inline string GetName() { return name; } const
	inline int GetHealth() { return health; } const
	inline int GetSpeed() { return speed; } const
	inline int GetStrength() { return strength; } const
	inline int GetLuck() { return luck; }  const

	//SET
	inline void SetName(string input_name) { name = input_name; }
	inline void SetHealth(int input_health) { health = input_health; }
	inline void SetSpeed(int input_speed) { speed = input_speed; }
	inline void SetStrength(int input_strength) { strength = input_strength; }
	inline void SetLuck(int input_luck) { luck = input_luck; }


	//Item and Inventory Functions
	bool UseItem(Item for_use, Being& use_from) //UseItem() without adding effects upon discard
	{
		for (unsigned int i = 0; i <= stock.size(); i++)
		{
			string t = stock[i].GetName();

			if (ItemCounter(for_use, use_from) == 0)
			{
				return false;
			}

			if (t == for_use.GetName())
			{
				stock.erase(stock.begin() +i);
				return true;
			}
		}
	}

	int ItemCounter(Item search, Being& ownerStock)									//Returns the count of an item in the merchants stock
	{
		int temp = 0;
		string temp_name = search.GetName();

		for (unsigned int i = 0; i < ownerStock.stock.size(); i++)
		{
			if ((ownerStock.stock[i]).GetName() == temp_name)
			{
				temp++;
			}
		}
		return temp;
	}

	int PrintStock(Being& owner)
	{
		cout << endl << owner.GetName() << "'s stock contains:\n";

		for (int i = 0; i < owner.stock.size(); i++)
		{
			cout << owner.stock[i].GetName();
		}

		cout << endl << endl;
		return 0;
	}

	bool EnoughStock(Item item, int quantity, Being& owner)	//Checks the owners stock for item quantity before Transfer() can be used
	{
		bool ans = false;

		if (ItemCounter(item, owner) >= quantity)
		{
			ans = true;
		}
		else
		{
			ans = false;
		}
		return ans;
	}

	void Transfer(int &amount,Being &takeFrom, Being &giveTo)															//Moves currency from being to being
	{
		takeFrom.value -= amount;
		giveTo.value += amount;
	}

	void Transfer(Item item, int count, Being& takeFrom, Being& giveTo)		//Moves a number of items to owner from other character in trade
	{
		int initialItemCount = ItemCounter(item, takeFrom);
		int i = 0;
		int tracker = count;
		string temp = item.GetName();
		do
		{
			if (takeFrom.stock[i].GetName() == temp)
			{
				giveTo.stock.push_back(takeFrom.stock[i]);
				takeFrom.stock.erase(takeFrom.stock.begin() + i);
				tracker--;
			}

			i++;

			if (i >= takeFrom.stock.size())
			{
				i = 0;
			}

		} while (tracker > 0);
	}
	
	
	//Battle Functions
	virtual void Attack(Being& target)
	{
		int damage = 0;
		srand(time(NULL));
		damage = GetStrength()*GetStrength() + (GetLuck() * rand() % 41);
		if (damage > target.GetHealth())
		{
			target.SetHealth(0);
		}
		else
		{
			target.SetHealth(target.GetHealth() - damage);
		}		cout << GetName() << " Attacked!!!\n";
	}

	virtual void Guard()
	{
		cout << "\n\nGuarding!!\n\n";
		SetHealth(GetHealth() + 90);
	}

	virtual bool Escape()
	{
		bool result = false;
		srand(time(NULL));
		result = ((GetSpeed() * (rand() % 11)) >= 50);
		cout << endl << GetName() << " Escaped!!!\n";
		return result;
	}

	bool Dodge(Being& target, int attacker)
	{
		bool answer = false;

		if (target.GetSpeed() >= 2*(attacker))
		{
			answer = true;
		}
		else if (target.GetSpeed() > attacker)
		{
			answer = (GetSpeed()*rand()%21 >= 30);
		}

		return answer;
	}
};
#endif /* beinginput_h */
