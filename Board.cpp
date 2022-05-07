#include "Board.h"

#include <iostream>

Board::Board() {
    Tile *tile = new Tile(' ', 0);
    // initialize board size
     board.resize(BOARD_SIZE, std::vector<Tile*> (BOARD_SIZE, tile));
}

void Board::printBoard(){
    std::vector<std::string> rows = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"}; // rows
    std::cout<<"    1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  " <<std::endl; //print column headers
    std::cout<<"  ------------------------------------------------------------- " <<std::endl;    
    int i = 0;
    for (std::vector<Tile*> row: board)
    {   
        std::cout<< rows[i] << " | "; //print row headers
        i++;  
        for (Tile* val: row) {
            std::cout << val->getLetter() << " | ";//print board contents
        }
        std::cout << std::endl;
    }
   
} 

Tile* Board::getTile(int row, int col){
    return board[row][col];
}
void Board::setTile(Tile* tile, int row, int col){
    board[row][col] = tile;
}