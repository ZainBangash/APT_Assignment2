#include "Player.h"


Player::Player(string name, Board* board) {
    this->name = name;
    this->score = 0;
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
