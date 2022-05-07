
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Letter type
typedef char Letter;

// Define a Value type
typedef int Value;

class Tile {
public:
   Tile(Letter letter, Value value);

   Letter letter;
   Value  value;
};


// used to store position information along side tile pointer
struct PlacedTile {
    Tile* tile;
    int x;
    int y;
};

#endif // ASSIGN2_TILE_H
