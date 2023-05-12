#include "game_of_life.h"

bool game_of_life::rand_value()
{
	return rand() % 4 == 0;
}

bool game_of_life::taken_cell(int i, int j)
{
    if (i < 0 || j < 0 || i >= ROW || j >= COLLUMN) {
        return false;
    }
    return _gen[i][j];
}

game_of_life::game_of_life()
{
    srand(time(nullptr));

    // generiramo random game state
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLLUMN; j++) {
            _gen[i][j] = rand_value();
        }
    }
}

void game_of_life::next_gen()
{
    // kalkuliramo sljedecu generaciju game state-a bazirano na trenutnoj
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLLUMN; j++) {
            int neighbors = 0;
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if ((ii >= 0 && ii < ROW) && (jj >= 0 && jj < COLLUMN) && !(ii == i && jj == j)) {
                        if (_gen[ii][jj]) {
                            neighbors++;
                        }
                    }
                }
            }

            if (_gen[i][j]) {
                // celija je ziva
                if (neighbors < 2 || neighbors > 3) {
                    _next_gen[i][j] = false; // celija umire
                }
                else {
                    _next_gen[i][j] = true; // celija prezivi
                }
            }
            else {
                // celija je mrtva
                if (neighbors == 3) {
                    _next_gen[i][j] = true; // nova celija se stvara
                }
                else {
                    _next_gen[i][j] = false; // celija ostaje mrtva
                }
            }
        }
    }

    // kopiramo sljedecu generaciju u trenutnu
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLLUMN; j++) {
            _gen[i][j] = _next_gen[i][j];
        }
    }
}

void game_of_life::draw()
{
    // iscrtavamo "game state"
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLLUMN; j++) {
            if (_gen[i][j]) {
                cout << "*";
            }
            else {
                cout << "_";
            }
        }
        cout << endl;
    }
}
