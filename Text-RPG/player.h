#ifndef player_h
#define player_h

#include "being.h"

class Player : public Being
{
public:
	Player()
	{
		SetHealth(1500);
		SetSpeed(5);
		SetStrength(5);
		SetLuck(1);
	}

	~Player() {}

	void Attack(Being& enemy)
	{
		int damage = 0;
		srand(time(NULL));

		if (Dodge(enemy, GetSpeed()))
		{
			damage = 0;
			cout << endl << enemy.GetName() << " Dodged your attack!!!\n\n";
		}
		else
		{
			damage = GetStrength() * 7 + (GetLuck() * rand() % 20);
			cout << "\nYou attacked " << enemy.GetName() << " and dealt " << damage << " damage!!!\n";
		}

		if (damage > enemy.GetHealth())
		{
			enemy.SetHealth(0);
		}
		else
		{
			enemy.SetHealth(enemy.GetHealth() - damage);
		}

		cout << "\nPlayer Health: " << GetHealth() << endl << endl;
		cout << enemy.GetName() << " Health: " << enemy.GetHealth() << endl << endl;
	}

	void Heal() 
	{
		SetHealth((GetHealth() + 235));
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
