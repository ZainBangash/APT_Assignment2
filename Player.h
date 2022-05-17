#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tile.h"
#include "LinkedList.h"
#include "Board.h"

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std:: endl;


class Player {
    public:
        Player(string name, int id, Board* board);
        ~Player();

        void addTileToHand(Tile* tile);
        bool hasTile(char tileLetter);
        Tile* getTile(char tileLetter);
        Tile* popTile(char tileLetter);
        void replaceTile(char letter, Tile* newTile);
        void removeTile(char letter);
        
        void printHand();
        string saveHand();
        bool isHandEmpty();
        
        int getID();
        int getPoints();
        string getName();
        void setPoints(int points);
        void addPoints(int pointsGained);


    private:
        LinkedList hand;
        int id;

        int points;
        string name;
        // need reference to board for validation
        Board* board;

};

#endif // ASSIGN2_PLAYER_H
