#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include <string>

#include "Tile.h"

#define BOARD_SIZE 15

class Board{
public:
    Board();
    //int putShip(const Ship &s);
    //void moveShips();
    //bool checkLimits()
    std::vector<std::vector<Tile*>> getBoard() const;
    void setVector(std::vector<std::vector<Tile*>> board);
    void printBoard();
    Tile* getTile(int row, int col);
    void setTile(Tile* tile, int row, int col);
    bool tileExists(int row, int col);

private:
    std::vector<std::vector<Tile*>> board;
};

#endif // ASSIGN2_BOARD_H