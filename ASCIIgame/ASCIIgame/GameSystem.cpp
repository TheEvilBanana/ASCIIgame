#include "GameSystem.h"



GameSystem::GameSystem()
{
	
	_fileHandle.gameTitle(titleFile);   //shows main screen

	system("PAUSE");

}



void GameSystem::gameLoop() {        
	
	_level.load(_player);
	bool gameOver = false;
	
	while (gameOver != true) {                  // main game loop
		_level.print(_player);                  // prints the map
		mainControl();                           // user control cycle
		_level.updateEnemies(_player);           // AI movement
		
	}
}

void GameSystem::mainControl() {
	char input; 
	input = _getch();                                 // User Input
	_level.movePlayer(input, _player);                 // Player movement
}