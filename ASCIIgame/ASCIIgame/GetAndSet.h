#pragma once
class GetAndSet {
public:
	GetAndSet();
	
	//setters
	virtual void setPosition(int x, int y);         // used forsetting player and enemy position

	//getters
	virtual void getPosition(int &x, int &y) = 0;        // used for getting player and enemy position

//private:
	int _x;
	int _y;
};

