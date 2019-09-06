#pragma once

#ifndef beinginput_h
#define beinginput_h

#include "stocked.h"

class Being : public Stocked
{
public:
	Being();
	~Being();

public:
	int health;
	int speed;
	int luck;
	int strength; 

	//GET
	inline int GetHealth() { return health; } const
	inline int GetSpeed() { return speed; } const
	inline int GetStrength() { return strength; } const
	inline int GetLuck() { return luck; }  const

	//SET
	inline void SetHealth(int input_health) { health = input_health; }
	inline void SetSpeed(int input_speed) { speed = input_speed; }
	inline void SetStrength(int input_strength) { strength = input_strength; }
	inline void SetLuck(int input_luck) { luck = input_luck; }

	//void Attack();
};
#endif /* beinginput_h */
