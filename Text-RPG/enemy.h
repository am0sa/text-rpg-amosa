#pragma once
#ifndef enemy_h
#define enemy_h

#include "being.h"

class Enemy : public Being
{
public:
	Enemy()
	{
		SetHealth(100);
		SetSpeed(5);
		SetStrength(3);
		SetLuck(1);
	}
	~Enemy() {}

	void attack(Being& player)
	{
		int damage = 0;
		srand(time(NULL));

		damage = GetStrength() * GetSpeed() + (GetLuck() * rand() % 101);

		cout << "\nYou were hit!! \nYou took " << damage << " damage!!!\n";

		player.SetHealth(player.GetHealth() - damage);

		system("PAUSE");

	}
};
#endif // !enemy
