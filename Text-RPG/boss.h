#pragma once
#ifndef boss_h
#define boss_h

#include "enemy.h"

class Boss : public Being
{
public:
	Boss() {};
	Boss(string input_name, int input_health, int input_speed, int input_luck, int input_strength, string input_special, int input_specialDamage)
	{
		SetName(input_name);
		SetHealth(input_health);
		SetSpeed(input_speed);
		SetLuck(input_luck);
		SetStrength(input_strength);
		SetEffectName(input_special);
		SetEffectDamage(input_specialDamage);
	}
	~Boss() {}
	
	unsigned int effectStacks = 1;
	unsigned int effectDamage = 10;
	unsigned int rageHealth = 3333;
	bool statusApplied = false;
	bool rageMode = false;
	string effectName = "";

	//SET
	inline int GetEffectDamage() { return effectDamage; }
	inline string GetEffectName() { return effectName; }

	//GET
	inline void SetEffectDamage(int input_effectDamage) { effectDamage = input_effectDamage; }
	inline void SetEffectName(string inputEffectName) { effectName = inputEffectName; }

	void Attack(Being& player)
	{
		if (GetHealth() > 0)
		{
			if (GetHealth() <= rageHealth)
			{
				rageMode = true;
			}

			int damage = 0;
			int bonusDMG = 0;
			srand(time(NULL));

			if (Dodge(player, GetSpeed()))
			{
				damage = 0;
				effectStacks--;
				cout << endl << "You dodged " << GetName() << "'s attack!!!\n";
			}
			else
			{
				damage = GetStrength() * GetStrength() * 4 + (GetLuck() * rand() % 20);
				bonusDMG = (effectStacks * effectDamage);
				effectStacks++;
				if (rageMode) { damage = (damage * 1.1); }
				cout << GetName() << " Attacked!! \nYou took " << damage << " damage!!!\n";
				cout << "You also took " << bonusDMG << " " << GetEffectName() << " damage\n";
			}

			if (damage >= player.GetHealth())
			{
				player.SetHealth(0);
			}
			else
			{
				player.SetHealth(player.GetHealth() - (damage + bonusDMG));
			}
			//If boss is better than player in any attribute, apply special effect
			if ((GetSpeed() > player.GetSpeed()) || GetLuck() > player.GetLuck())
			{

			}

			cout << "\n\nPlayer Health: " << player.GetHealth() << endl << endl;
			cout << GetName() << " Health: " << GetHealth() << endl << endl;
			cout << "\n";
		}
		else
		{
			NULL;
		}
	}
};
#endif // !boss
