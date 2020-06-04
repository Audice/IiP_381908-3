#pragma once
#include <vector>
#include "field.h"

using namespace std;

class Player {
	field own, enemy;
	vector<Ship> ships;
public:
	int shipsAlive;
	Player();
	void print();
	void readShips();
	void setOpponent(Player& p);
	bool placeShip(Ship& ship, bool isRand);
	void setRandomShips();
	int shoot(int x, int y); 
	char checkHit(int x, int y);
	void registerHit(char ch, int x, int y);
};

