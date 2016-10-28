#include "Enemy.h"



Enemy::Enemy(string name,char tile, int health, int attack) {   //Initiate Enemy 
	_name = name;
	_health = health;
	_attack = attack;
	_tile = tile;
}

char Enemy::getMoveEnemy(int playerX, int playerY) {      // Calaculates the movement of the Enemy

	int distanceFromPlayer;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx); 
	int ady = abs(dy);
	distanceFromPlayer = adx + ady;           // calculate the distance from the player to decide the next move
	if (distanceFromPlayer <= 3) {
		if (adx > ady) {
			if (dx > 0) {
				return 'a';
			}
			else {
				return 'd';
			}
		}
		else {
			if (dy > 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}

	int randomMove = randomGen(5,1);           // randomly moves to one of direction when player is not class
	switch (randomMove) {
	case 1:
		return 'a';
	case 2:
		return 'w';
	case 3:
		return 's';
	case 4:
		return 'd';
	default:
		return '.';

	}
}



