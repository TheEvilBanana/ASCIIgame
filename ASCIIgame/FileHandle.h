#pragma once
#include <string>
#include <vector>
using namespace std;

class FileHandle
{
public:
	FileHandle();
	

	void gameTitle(string fileName);
	
private:

	vector <string> _openTitle;            // vector that stores the string from the text file

	

};

