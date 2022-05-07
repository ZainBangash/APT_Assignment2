
#include "Tile.h"
Tile::Tile(Letter letter, Value value)
{
   this->letter = letter;
   this->value = value;

}

// Tile::~Tile(){
//    delete& letter;
//    delete value;
// }

Letter Tile::getLetter(){
   return letter;
}