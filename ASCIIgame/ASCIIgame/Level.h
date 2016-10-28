#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "FileHandle.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
//#include "GameSystem.h"

#define swordDmg 7
#define hammerDmg 10
#define axeDmg 13
#define findGold 3

using namespace std;

class Level
{
public:
	Level();
	
	void load(Player &player);           // Loads the new map
	void saveFile(Player &player);       // save the current map
	void loadFile(Player &player);          // load the saved map
	void movePlayer(char input, Player &player);   // used for Player movement
	void print(Player &player);                // prints the map after every turn
	//getter
	char getTile(int x, int y);
	//setter
	void setTile(int x, int y, char tile);

	void battle(Player &player, int targetX, int targetY);                      // Used to process combat between player and enemy
	void updateEnemies(Player &player);                                         // used to move the enemies to new position if they move
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);   // used for processign the enemy AI move
	
	void winCondition(Player &player);                              // checks the win condition for the player
	
private:
	void processMove(Player &player, int targetX, int targetY);          // This process the player movement on the map
	void excHandle();
	double division(int a, int b);
	const int x = 50;
	const int y = 0;
	double z = 0;


	FileHandle _fileHandle;
	string levelFile;
	string savefile;
	vector <string>  _levelData;

	Player _player;
	Item _item;
	Sword _sword;
	Hammer _hammer;
	Axe _axe;
	//Enemy _enemy;
	vector <Enemy> _enemies;
};

