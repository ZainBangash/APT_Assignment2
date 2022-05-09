#ifndef A2_TILEBAG
#define A2_TILEBAG

#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using std::string;
using std::vector;

class TileBag {
    public:
        TileBag();
        ~TileBag();

        void addTile(Tile* tile);
        Tile* popTile();
        int tilesLeft();
        void shuffleTiles();

    private:
        LinkedList bag;
};

#endif
