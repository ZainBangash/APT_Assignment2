#include <vector>
#include <iostream>

#include "Board.h"

using std::cout;
using std::endl;


Board::Board() {
    // initialize board size
    vector<vector<Tile*>> board( BOARD_SIZE , vector<Tile*> (BOARD_SIZE, nullptr));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == nullptr) {
                cout << 0;
            }
        }
        cout << endl;
    }


}

Board::~Board() {

}
