#ifndef A2_SCRABBLE
#define A2_SCRABBLE

#include "Board.h"
#include "Tile.h"
#include "Player.h"
#include "TileBag.h"

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <set>

using std::vector;
using std::string;
using std::stoi;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::set;
using std::cin;
using std::cout;
using std::endl;

#define HAND_SIZE 7

class Scrabble {
    public:
        Scrabble(string tileFile);
        ~Scrabble();

        void run();

    private:
        TileBag tileBag;
        Board board;
        vector<Player*> players;
        int currentPlayer;
        bool endGame;

        void mainMenu();
        bool playGame();
        void addPlayer(int playerNum);
        bool checkName(string name);
        bool loadGame(string fileName);
        void result();

        int letterToTileVal(char l);


        void checkCommand(string command, vector<PlacedTile>* tilesPlaced, set<Tile*>* tilesPoints, bool* savedGame);


        void placeTile(vector<string> tokens, vector<PlacedTile>* tilesPlaced, set<Tile*>* tilesPoints);
        void points(set<Tile*> tilesPoints, int row, int col, Tile* tile);
        bool validateTilePlacement(vector<PlacedTile> tilesPlaced);

};


#endif //A2_SCRABBLE
