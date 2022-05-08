#include "Player.h"

Player::Player(std::string name, int points){
   this->name = name;
   this->points = points;
}

void Player::addTileToHand(Tile* tile) {
    hand.add_back(tile);
}

// returns true when the player has a specific tile in their hand
bool Player::hasTile(char tileLetter) {
    bool result = false;
    for (int i = 0; i < hand.size(); i++) {
        Tile* tilePtr = hand.get(i);
        if (tilePtr != nullptr && tilePtr->letter == tileLetter) {
            result = true;
        }
    }
    return result;
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

