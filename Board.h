#ifndef A2_BOARD
#define A2_BOARD

#define BOARD_SIZE 15

#include <vector>

#include "Tile.h"

using std::vector;

class Board {
public:
    Board();
    ~Board();

    Tile* getTile(int x, int y);

    void setTile(int x, int y, Tile*);

    void printBoard();

private:
    vector<vector<Tile*>> board;
};


#endif // end A2_BOARD
