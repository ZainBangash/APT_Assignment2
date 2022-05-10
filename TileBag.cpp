#include "TileBag.h"


TileBag::TileBag() {
    std::srand ( unsigned ( std::time(0) ) );
};

TileBag::~TileBag() {};


void TileBag::loadTiles(istream &strm) {

    for(string line; getline(strm, line);) {

        std::string inter;
        std::vector<std::string> tokens;
        std::stringstream check1(line);
        while(getline(check1, inter, ' ')){ //tokenizes command string
            tokens.push_back(inter);
       }

       // Tile(char letter, int value)
       bag.add_front(new Tile(tokens[0].at(0), stoi(tokens[1])));

    }
};

void TileBag::addTile(Tile* tile) {
    bag.add_front(tile);
}


Tile* TileBag::popTile() {
    Tile* retTile = bag.get(0);
    bag.remove_front();
    return retTile;

};

int TileBag::tilesLeft() {
    return bag.size();
}

void TileBag::shuffleTiles() {
    vector<Tile*> tmp;
    //
    while (bag.size() > 0) {
        tmp.push_back(bag.get(0));
        bag.remove_front();
    }

    // use the system's random device
    std::random_device r;
    std::shuffle(tmp.begin(), tmp.end(), std::default_random_engine(r()));


    while (tmp.size() > 0) {
        bag.add_front(tmp[tmp.size() - 1]);
        tmp.pop_back();
    }
}
