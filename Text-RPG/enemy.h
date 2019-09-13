#pragma once
#ifndef enemy_h
#define enemy_h

#include "being.h"

class Enemy : public Being
{
public:
	Enemy() {};
	~Enemy() {}

	void Attack(Being& player)
	{
		if (GetHealth() > 0)
		{
			int damage = 0;
			srand(time(NULL));

			if (Dodge(player, GetSpeed()))
			{
				damage = 0;
				cout << endl << "You dodged " << GetName() << "'s attack!!!\n";
			}
			else
			{
				damage = GetStrength() * GetStrength() * 4 + (GetLuck() * rand() % 20);
				cout << GetName() << " Attacked!! \nYou took " << damage << " damage!!!\n";
			}


			if (damage >= player.GetHealth())
			{
				player.SetHealth(0);
			}
			else
			{
				player.SetHealth(player.GetHealth() - damage);
			}

			cout << "\n\nPlayer Health: " << player.GetHealth() << endl << endl;
			cout << GetName() << " Health: " << GetHealth() << endl << endl;

			system("PAUSE");
			cout << "\n";
		}
		else
		{
			NULL;
		}
	}
};
#endif // !enemy
