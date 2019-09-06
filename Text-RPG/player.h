#ifndef player_h
#define player_h

#include "being.h"

class Player : public Being
{
public:
	Player();
	~Player();

	void attack(Being& enemy)
	{
		int damage = 0;
		srand(time(NULL));

		damage = GetStrength() * GetSpeed() + (GetLuck() * rand()%101) ;
		
		cout << "\nYou attacked " << enemy.GetName() << " and dealt " << damage << " damage!!!\n";

		enemy.SetHealth(enemy.GetHealth() - damage);
	}
};
#endif // !player_h
