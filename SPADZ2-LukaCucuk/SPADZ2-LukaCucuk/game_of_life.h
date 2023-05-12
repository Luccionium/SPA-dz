#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLLUMN = 40;
	static const unsigned int ROW = 20;
	bool _gen[ROW][COLLUMN];
	bool _next_gen[ROW][COLLUMN];
	bool rand_value();
	bool taken_cell(int i, int j);

public:
	game_of_life();
	void next_gen();
	void draw();
};

#endif
