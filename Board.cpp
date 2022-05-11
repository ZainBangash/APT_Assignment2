#include "Board.h"


Board::Board() {
    // initialize board size
    board.resize(BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].resize(BOARD_SIZE);
    }

}


Board::~Board() {
    // it is probably the board class's job to clean up tiles placed down
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (tileExists(col, row)) {
                delete board[row][col];
            }
        }
    }

}

bool Board::tileExists(int x, int y) {
    return board[y][x] != nullptr;
}


Tile* Board::getTile(int x, int y) {
    return board[y][x];
}


void Board::setTile(int x, int y, Tile* tile) {
    board[y][x] = tile;
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
    for (int row = 0; row < BOARD_SIZE; row++) {
        // Print line letter
        lineLetter = 'A' + row;
        cout << " " << lineLetter << " |";

        // Print tiles
        for (int col = 0; col < BOARD_SIZE; col++) {

            if (tileExists(col, row)) {
                cout << " " << getTile(col, row)->letter << " |";
            } else {
                cout << "   |";
            }
        }
        cout << endl;
    }

}
