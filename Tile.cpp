#include "Tile.h"

Tile::Tile(char letter, int value) {
   this->letter = letter;
   this->value = value;
};


char Tile::getLetter() {
    return letter;
}

int Tile::getValue() {
    return value;
}
