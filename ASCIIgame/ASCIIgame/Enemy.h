 #pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "GetAndSet.h"
#define randomGen(a,b) (rand() %a + b)


using namespace std;
class Enemy : public GetAndSet
{
public:
	Enemy(string name,char tile, int health, int attack);  //initiate enemy

	char getTile() { return _tile; }                    // get the enemy tile representation

	void getPosition(int & x, int & y) {                   // get enemy position on map
		x = _x;
		y = _y;
	}

	char getMoveEnemy(int playerX, int playerY);              // Move the enemy using AI

	string _name;
	int _health;
	int _attack;
	char _tile;


};


