#ifndef A2_PLAYER
#define A2_PLAYER

#include "Tile.h"
#include "LinkedList.h"
#include "Board.h"

#include <vector>

using std::vector;


class Player {
    public:
        Player();
        ~Player();
        bool validate(vector<PlacedTile> tilesPlaced);
        bool hasTile(Letter l);

    private:
        LinkedList hand;
        // need reference to board for validation
        Board* board;

};


// also for validation
enum WordDirection {
    Horizontal,
    Vertical
};

#endif
