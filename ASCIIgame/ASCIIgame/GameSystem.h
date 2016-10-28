#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include "FileHandle.h"
#include "Level.h"
#include "Player.h"
using namespace std;
class GameSystem
{
public:
	GameSystem();
	
	void gameLoop();
	void mainControl();

private:
	const string titleFile = "GameTitle.txt";       
	FileHandle _fileHandle;
	Level _level;
	Player _player;
};

