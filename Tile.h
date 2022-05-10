#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H


class Tile {
public:
   Tile(char letter, int value);

   char letter;
   char  value;
};

// used to store position information along side tile pointer
struct PlacedTile {
    Tile* tile;
    int x;
    int y;
};

#endif // ASSIGN2_TILE_H
