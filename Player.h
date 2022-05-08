#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tile.h"
#include "LinkedList.h"

#include <string>

class Player {
public:
   Player(std::string name, int points);
   //~Player();
   int getPoints();
   std::string getName();
   void setPoints(int points);
   void addTileToHand(Tile* tile);
   bool hasTile(Letter l);

private: 
    std::string name;
    int points;
    LinkedList hand;

};

#endif // ASSIGN2_PLAYER_H 