#include "Item.h"



Item::Item() {
}

int Item::useItem(int value, Player &player) {            // function overload to use gold
	toGold = &(player._gold);
	*toGold = *toGold + value;
	cout << "You got "<< value << " gold !" << endl;
	system("PAUSE");
	return 0;
}

void Item::useItem(Player &player) {                            // function overload to use potion
	int potion = 4;
	toPotion = &(player._health);
	*toPotion += potion;
	cout << "You used a potion, healed for 4 health !" << endl;
	system("PAUSE");
}

Item::~Item() {
	delete toGold;
	delete toPotion;
}


Sword::Sword() {

}

Hammer::Hammer() {

}




Weapon::Weapon() {


}

void Weapon::equipWeapon(int damage, Player &player) {
	_player._attack = damage;
	
}


Axe::Axe() {
}
