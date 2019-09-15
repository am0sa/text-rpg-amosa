#pragma once
#ifndef enemy_h
#define enemy_h

#include "being.h"

class Enemy : public Being
{
public:
	Enemy() {};
	Enemy(string input_name, int input_health, int input_speed, int input_luck, int input_strength)
	{
		SetName(input_name);
		SetHealth(input_health);
		SetSpeed(input_speed);
		SetStrength(input_strength);
	}
	~Enemy() {}

	void Attack(Being& player)
	{
		if (GetHealth() > 0)
		{
			int damage = 0;
			srand((unsigned)time(NULL));

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
			cout << "\n";
		}
		else
		{
		}
	}
};
#endif // !enemy
