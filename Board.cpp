#include "Board.h"


Board::Board() {
    // initialize board size
    // DOESNT WORK, BECOMES LOCAL FOR SOME STUPID REASON
    // WHY DOES HEADDER FILE DO INITIALIZATION!!!!
    //vector<vector<Tile*>> board( BOARD_SIZE , vector<Tile*> (BOARD_SIZE, nullptr));
    //board.resize(BOARD_SIZE);
    //for (vector<Tile*> i : board) {i.resize(BOARD_SIZE);}
    board.resize(BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].resize(BOARD_SIZE);
    }

    board[4][4] = new Tile('Z', 10);

    printBoard();


}

Board::~Board() {
    // it is probably the board class's job to clean up tiles placed down

}


void Board::printBoard() {
    // Print top line
    cout << "    ";
    for (int i = 1; i < BOARD_SIZE + 1; i++) {
        cout << " ";
        if (i < 10) {
            cout << i << "  ";
        } else {
            cout << i << " ";;
        }
    }
    cout << endl;


    // Print seperator
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE*4 + 2; i++) {
        cout << "-";
    }
    cout << endl;

    char lineLetter;
    // Print each line
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Print line letter
        lineLetter = 'A' + i;
        cout << " " << lineLetter << " |";

        // Print tiles
        for (int j = 0; j < BOARD_SIZE; j++) {

            if (board[i][j] == nullptr) {
                cout << "   |";
            } else {
                cout << " " << board[i][j]->letter << " |";
            }
        }
        cout << endl;
    }



}
