#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>

class Player {
public:
   Player(std::string name, int points);
   //~Player();
   int getPoints();
   std::string getName();
   void setPoints(int points);

private: 
    std::string name;
    int points;
};

#endif // ASSIGN2_PLAYER_H 