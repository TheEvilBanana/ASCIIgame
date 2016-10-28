#include "Player.h"



Player::Player() {
	
}


void Player::init(int health, int attack, string weaponName, int gold) { // initiating the player
	_health = health;
	_attack = attack;
	_weaponName = weaponName;
	_gold = gold;
}

