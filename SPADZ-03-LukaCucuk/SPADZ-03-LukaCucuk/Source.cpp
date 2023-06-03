#include "DijkstraShortestPath.h"

using namespace std;


int main()
{

    cout << "If points A or B are blocked by randomly placed walls, please restart! :)" << endl;
    cout << endl;
    bool walls = true;
    cout << "Press (1) if you want a simulation with walls or press (0) for a simulation without walls: ";
    cin >> walls;

    int row_a;
    int column_a;
    int row_b;
    int column_b;

    cout << "Rows 1 - 20" << endl;
    cout << "Columns 1 - 40" << endl;

    cout << "Insert point A row: ";
    cin >> row_a;
    cout << "Insert point A column: ";
    cin >> column_a;
    cout << "Insert point B row: ";
    cin >> row_b;
    cout << "Insert point B column: ";
    cin >> column_b;

    DijkstraShortestPath path(row_a, column_a, row_b, column_b, walls);

    return 0;
}
