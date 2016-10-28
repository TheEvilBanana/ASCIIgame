#pragma once
#include "Player.h"
#include <iostream>
using namespace std;


class Item {
public:
	Item();
	int *toGold = new int;
	int *toPotion = new int;
	int useItem(int value, Player &player);                                              // function overloading
	void useItem(Player &player);
	friend Item& operator+ (Item &left, Item &right) {left = left + right;return left;}  // operator overloading
	~Item();
};

class Weapon {
	
public:
	Weapon();
	//int damage;
	//string  name;
	virtual void equipWeapon(int damage, Player &player);     // virtual function
	
private:
	Player _player;
};

struct Sword : public Weapon {
	Sword();
	const string name = "Sword";
	virtual void equipWeapon(int damage, Player &player) override{    //virtual override function
		player._attack = damage;
		player._weaponName = name;

		cout << "You got a sword, attack became 7" << endl;
		system("PAUSE");
	};
};

struct Hammer : public Weapon {
	Hammer();
	const string name = "Hammer";
	virtual void equipWeapon(int damage, Player &player) override {       //virtual override function
		player._attack = damage;
		player._weaponName = name;

		cout << "Its Hammer Time" << endl;
		system("PAUSE");
	};
};

struct Axe : public Weapon {
	Axe();
	const string name = "Axe";
	virtual void equipWeapon(int damage, Player &player) override {         //virtual override function
		player._attack = damage;
		player._weaponName = name;

		cout << "The might of AXE" << endl;
		system("PAUSE");
	};
};





