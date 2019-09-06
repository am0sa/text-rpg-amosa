#ifndef being_h
#define being_h

#include "stocked.h"

class Being : public Stocked
{
public:
	Being();
	~Being();

protected:
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
	inline void SetHealth(int _health) { health = _health; }
	inline void SetSpeed(int _speed) { speed = _speed; }
	inline void SetStrength(int _strength) { strength = _strength; }
	inline void SetLuck(int _luck) { luck = _luck; }

	void Attack();

private:
};
#endif /* being_h */
