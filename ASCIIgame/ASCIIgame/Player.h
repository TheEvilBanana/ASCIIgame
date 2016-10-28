#pragma once
#include <string>
#include "GetAndSet.h"
using namespace std;

class Player : public GetAndSet 
{
public:
	Player();
	void init(int health, int attack, string weaponName, int gold);  // initiate player

	
	void getPosition(int & x, int & y) {                  // get player postion
		x = _x;
		y = _y;
	}
	
	int _health;
	int _attack;
	string _weaponName;
	int _gold;
	
};

