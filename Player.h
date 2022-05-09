#ifndef A2_PLAYER
#define A2_PLAYER

#include "Tile.h"
#include "LinkedList.h"
#include "Board.h"

#include <vector>

using std::vector;
using std::string;


class Player {
    public:
        Player(string name, Board* board);
        ~Player();
        bool validate(vector<PlacedTile> tilesPlaced);
        void addTileToHand(Tile* tile);
        bool hasTile(char tileLetter);
        Tile* popTile(char tileLetter);
        void replaceTile(char letter, Tile* tile);
        void removeTile(char letter);

    private:
        LinkedList hand;
        int score;
        string name;
        // need reference to board for validation
        Board* board;

};


// also for validation
enum WordDirection {
    Horizontal,
    Vertical
};

#endif
