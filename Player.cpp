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


Tile* Player::getTile(char tileLetter) {
    Tile* result = nullptr;
    for (int i = 0; i < hand.size(); i++) {
        Tile* tilePtr = hand.get(i);
        if (tilePtr != nullptr && tilePtr->letter == tileLetter) {
            result = tilePtr;
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


void Player::removeTile(char tileLetter) {

    int tileIndex = -1;

    for (int i = 0; i < hand.size(); i++) {
        Tile* tilePtr = hand.get(i);
        if (tilePtr != nullptr && tilePtr->letter == tileLetter) {
            tileIndex = i;
        }
    }
    if (tileIndex != -1) {
        hand.remove(tileIndex);
    }

}


void Player::replaceTile(char letter, Tile* newTile) {
    int tileIndex = -1;
    Tile* tilePtr = nullptr;
    for (int i = 0; i < hand.size(); i++) {
        tilePtr = hand.get(i);
        if (tilePtr != nullptr && tilePtr->letter == letter) {
            tileIndex = i;
        }
        //delete tilePtr;
    }
    if (tileIndex != -1) {
        //replace tile
        hand.remove(tileIndex);
        hand.add_front(newTile);
    }

    // tile is out of the game
    //delete tilePtr;

}


void Player::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        Tile* tile = hand.get(i);
        std::printf("%c-%d ", tile->letter, tile->value);
    }
    cout << endl;
}


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
