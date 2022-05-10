#include "Player.h"



Player::Player(string name, int id, Board* board){
   this->name = name;
   this->points = 0;
   this->id = id;
   this->board = board;
}


Player::~Player() {}


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

};


Tile* Player::popTile(char tileLetter) {

    int tileIndex = -1;

    for (int i = 0; i < hand.size(); i++) {
        Tile* tilePtr = hand.get(i);
        if (tilePtr != nullptr && tilePtr->letter == tileLetter) {
            tileIndex = i;
        }
    }
    Tile* result;
    if (tileIndex != -1) {
        result = hand.get(tileIndex);
        hand.remove(tileIndex);
    } else {
        result = nullptr;
    }

    return result;

}


//TODO
Tile* Player::replaceTile(char letter, Tile* newTile) {return nullptr;}


int Player::getID() {
    return this->id;
}

int Player::getPoints(){
    return points;
}

string Player::getName(){
    return name;
}


void Player::setPoints(int points){
    this->points = points;
}


void Player::addPoints(int pointsGained) {
    this->points = this->points + pointsGained;
}
