#ifndef A2_BOARD
#define A2_BOARD

#define BOARD_SIZE 15

#include <vector>
#include <iostream>

#include "Tile.h"

using std::vector;

using std::cout;
using std::endl;

class Board {
public:
    Board();
    ~Board();

    bool tileExists(int x, int y);

    Tile* getTile(int x, int y);

    void setTile(int x, int y, Tile*);

    void printBoard();

private:
    vector<vector<Tile*>> board;
};


#endif // end A2_BOARD
