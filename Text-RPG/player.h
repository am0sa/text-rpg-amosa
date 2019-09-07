#ifndef player_h
#define player_h

#include "being.h"

class Player : public Being
{
public:
	Player()
	{
		SetHealth(100);
		SetSpeed(5);
		SetStrength(3);
		SetLuck(1);
	}

	~Player() {}

	void Attack(Being& enemy)
	{
		int damage = 0;
		srand(time(NULL));
		damage = GetStrength() * GetSpeed() + (GetLuck() * rand()%101) ;
		cout << "\nYou attacked " << enemy.GetName() << " and dealt " << damage << " damage!!!\n";
		
		if (damage > enemy.GetHealth())
		{
			enemy.SetHealth(0);
		}
		else
		{
			enemy.SetHealth(enemy.GetHealth() - damage);
		}
	}

	void Heal() 
	{
		SetHealth((GetHealth() + 35));
	}

	bool Escape()
	{
		bool result = false;
		srand(time(NULL));
		result = ((GetSpeed() * (rand() % 11)) >= 50);

		if (result)
		{
			cout << "\n\nEscape Failed!!\n\n";
		}
		else
		{
			cout << "\nYou escaped!!!\n";
		}
		return result;
	}

};
#endif // !player_h
