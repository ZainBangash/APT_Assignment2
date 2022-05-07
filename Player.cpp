#include "Player.h"

Player::Player(std::string name, int points){
   this->name = name;
   this->points = points;
}

// Player::~Player() {
//    delete name;
//    delete points;
// }

int Player::getPoints(){
    return points;
}

std::string Player::getName(){
    return name;
}


void Player::setPoints(int points){
    this->points = points;
}

