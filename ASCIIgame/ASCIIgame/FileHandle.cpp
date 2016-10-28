#include "FileHandle.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>


FileHandle::FileHandle()
{
}




void FileHandle::gameTitle(string fileName) {
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		cout << "Error";
		system("PAUSE");
		exit(0);
	}

	string line;

	while (getline(file, line)) {
		_openTitle.push_back(line);
	}
	file.close();

	for (unsigned int i = 0; i < _openTitle.size(); i++) {
		cout << _openTitle[i] << endl;
	}
	cout << endl;

}



