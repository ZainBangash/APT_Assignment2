#ifndef A2_TILEBAG
#define A2_TILEBAG

#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>

using std::string;
using std::vector;

using std::istream;
using std::getline;
using std::stoi;

class TileBag {
    public:
        TileBag();
        ~TileBag();

        void loadTiles(istream &strm);
        void addTile(Tile* tile);
        Tile* popTile();
        int tilesLeft();
        void shuffleTiles();
        string saveBag();

    private:
        LinkedList bag;
};

#endif
