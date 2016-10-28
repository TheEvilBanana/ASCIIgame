#include "Level.h"



Level::Level()
{
}




void Level::load(Player &player) {           // load new map when game starts
	levelFile = "level1.txt";
	ifstream file;
	file.open(levelFile);
	if (file.fail()) {
		cout << "Error";
		system("PAUSE");
		exit(0);
	}

	string line;
	
	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();

	char tile;

	for (unsigned int i = 0; i < _levelData.size(); i++) {
		for (unsigned int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			case'@'://Player
				player.setPosition(j, i);
				player.init(15, 4, "Hands", 0);
				break;
			case'#'://Walls
				_levelData[i][j] = (char)(219);
				break;
			case 'e':
				_enemies.push_back(Enemy("Small enemy",'e', 5, 2));
				_enemies.back().setPosition(j, i);
				break;
			case'E':
				_enemies.push_back(Enemy("Big enemy", 'E',11, 7));
				_enemies.back().setPosition(j, i);
			default:
				break;
			}
		}
	}
}

void Level::saveFile(Player &player) {             // save the game state to a text file
	savefile = "SaveFile.txt";
	ofstream file;
	file.open(savefile);
	if (file.fail()) {
		cout << "Error: could not open file";
		system("PAUSE");
	}
	for (unsigned int i = 0; i < _levelData.size(); i++) {
		file << _levelData[i] << endl;
	}

	file.close();

	savefile = "SaveData.txt";
	file.open(savefile);
	if (file.fail()) {
		cout << "Error: could not open file";
		system("PAUSE");
	}
	file << player._health << endl;
	file << player._attack << endl;
	file << player._weaponName << endl;
	file << player._gold << endl;
	file.close();
}

void Level::loadFile(Player &player) {        // load game from a saved game
	levelFile = "SaveFile.txt";
	ifstream file;
	file.open(levelFile);
	if (file.fail()) {
		cout << "Error";
		system("PAUSE");
		exit(0);
	}

	string line;
	_levelData.clear();
	_enemies.clear();
	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();

	char tile;

	for (unsigned int i = 0; i < _levelData.size(); i++) {
		for (unsigned int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			case'@'://Player
				player.setPosition(j, i);
				player.init(15, 4, "Hands", 0);
				break;
			case(char)(219) ://Walls
				//_levelData[i][j] = (char)(219);
				break;
			case 'e':
				_enemies.push_back(Enemy("small enemy", 'e', 5, 2));
				_enemies.back().setPosition(j, i);
				break;
			case'E':
				_enemies.push_back(Enemy("Big enemy", 'E', 11, 7));
				_enemies.back().setPosition(j, i);
			default:
				break;
			}
		}
	}

	levelFile = "SaveData.txt";

	file.open(levelFile);
	if (file.fail()) {
		cout << "Error";
		system("PAUSE");
		exit(0);
	}
	int hlth;
	int dmg;
	string wpn;
	int gld;
	file >> hlth;
	file >> dmg;
	file >> wpn;
	file >> gld;
	file.close();
	
	player._health = hlth;
	player._attack = dmg;
	player._weaponName = wpn;
	player._gold = gld;


}

void Level::print(Player &player) {        // prints the screen every turn

	system("CLS");
	cout << flush;

	for (unsigned int i = 0; i < _levelData.size(); i++) {
		cout << _levelData[i] << endl;
	}
	cout << endl;
	cout << "Raid the cave !!" << endl;

	cout << "Move player with w/a/s/d |  Save with 't' | Load with 'y' " << endl;

	cout << "Health :" << player._health << "   Attack :" << player._attack << "   Weapon :" << player._weaponName << "    Gold:" << player._gold << endl;
	cout << "Legend: e-Small enemy|E-Big enemy|g-gold|p-Heal potion|!-Win Point|s,h,a-new weapons" << endl;
	cout << "\n ";
}


void Level::movePlayer(char input, Player &player) {          // User player controls
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	
	switch (input) {
	case'w':
	case'W':
		processMove(player, playerX, playerY - 1);
		break;
	case's':
	case'S':
		processMove(player, playerX, playerY + 1);
		break;
	case'a':
	case'A':
		processMove(player, playerX - 1, playerY);
		break;
	case'd':
	case'D':
		processMove(player, playerX + 1, playerY);
		break;
	case't':
	case'T':
		saveFile(player);
		break;
	case 'y':
	case 'Y':
		loadFile(player);
		break;
	default:
		cout << "\nINVALID INPUT"<<endl;
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y) {       
	char a = _levelData[y][x];
	return _levelData[y][x];

}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}



void Level::processMove(Player &player, int targetX, int targetY) {       // used for processing the players chosen movement
	int playerX;
	int playerY;
	
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
	case('.'):
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case((char)(219)):
		cout << "You bumped into a wall !" << endl;
		system("PAUSE");
		break;

	case'e':
		battle(player, targetX, targetY);
		break;
	case 'E':
		battle(player, targetX, targetY);
		break;
	case 'p':
		_item.useItem(player);
		setTile(targetX, targetY, '.');
		//player._health += 4;
		break;
	case 'g':
		_item.useItem(findGold,player);
		setTile(targetX, targetY, '.');
		break;
	case 's':
		_sword.equipWeapon(swordDmg,player);
		setTile(targetX, targetY, '.');
		break;
	case 'h':
		_hammer.equipWeapon(hammerDmg, player);
		setTile(targetX, targetY, '.');
		break;
	case 'a':
		_axe.equipWeapon(axeDmg, player);
		setTile(targetX, targetY, '.');
	case'!':
		winCondition(player);
		break;

	case '/':
		excHandle();
		break;

	default:
		break;
	}

}



void Level::battle(Player &player, int targetX, int targetY) {    // simulates the battle between enemy and player
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	//int attackTurn;
	//int attackResult;
	string enemyName;
	int enemyHealth;
	player.getPosition(playerX, playerY);
	//int  playerAttack = player._attack;
	//int enemyHealth;
	for (unsigned int i = 0; i < _enemies.size(); i++) {
		_enemies[i].getPosition(enemyX, enemyY);
		//enemyName = _enemies[i]._name;
		//int enemyHealth = _enemies[i]._health;
		if (targetX == enemyX && targetY == enemyY) {
			
			enemyHealth = (_enemies[i]._health) - (player._attack);
			if (enemyHealth <= 0) {
				
				setTile(targetX, targetY, '.');
				cout << "You fought " << _enemies[i]._name << "\nIt is Dead !" << endl;
				//_enemies.erase(_enemies.begin() + i);
				_enemies[i] = _enemies.back();                                     // removing dead enemies from enemy vector
				_enemies.pop_back();
				i--;
				system("PAUSE");
				return;
			}
			else {
				_enemies[i]._health = enemyHealth;
				player._health -= _enemies[i]._attack;
				cout << "You fought " << _enemies[i]._name << "\nIt is still alive, it did " << _enemies[i]._attack << " damage to you !" << endl;
				if (player._health <= 0) {       // checking to see if player is still alive or not
					cout << "You Died, Game Over !!" << endl;
					system("PAUSE");
					exit(0);
				}
				system("PAUSE");
				return;
			}
		}
	}
}

void Level::updateEnemies(Player & player) {            // update enemymovement based on the AI
	char enemyMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	player.getPosition(playerX, playerY);

	for (unsigned int i = 0; i < _enemies.size(); i++) {
		enemyMove = _enemies[i].getMoveEnemy(playerX, playerY);
		_enemies[i].getPosition(enemyX, enemyY);
		
		switch (enemyMove) {
		case'w':
		//case'W':
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case's':
		//case'S':
			processEnemyMove(player, i, enemyX, enemyY + 1);
			break;
		case'a':
		//case'A':
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		case'd':
		//case'D':
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		
		}

	}
}

void Level::processEnemyMove(Player & player, int enemyIndex, int targetX, int targetY) {  // Enemy movement AI
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;
	_enemies[enemyIndex].getPosition(enemyX, enemyY); 
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {
	case('.'):
		_enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, _enemies[enemyIndex].getTile());
		break;
	case((char)(219)):
		break;
	}
}

void Level::winCondition(Player & player) {             // Check winning condition
	if (player._gold >= 6) {
		cout << "Congrats, you have collected enough gold. YOU WIN !!" << endl;
		system("PAUSE");
		exit(0);
	}
	else {
		cout << "You do not have enough gold to win, raid around !!" <<endl;
		system("PAUSE");
		return;
	}
}

void Level::excHandle() {
	try {
		z = division(x, y);
		cout << z << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("PAUSE");
	}

}

double Level::division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition! \n What is this doing in a cave, It will forever be a mystery !!";
	}
	return (a / b);
}
