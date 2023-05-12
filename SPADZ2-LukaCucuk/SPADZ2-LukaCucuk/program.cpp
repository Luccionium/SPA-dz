#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	
	bool dalje;
	do {
		the_game.draw();
		the_game.next_gen();
		
		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}