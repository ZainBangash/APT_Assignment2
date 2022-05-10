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

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

class Scrabble {
    public:
        Scrabble(string tileFile);
        ~Scrabble();

        void run();

    private:
        TileBag tileBag;
        Board board;
        vector<Player*> players;

        void mainMenu();
        bool addPlayer(int playerNum);
        bool checkCommand(string command);
        bool checkName(string name);
        bool fileExists(string fileName);

};


#endif //A2_SCRABBLE
