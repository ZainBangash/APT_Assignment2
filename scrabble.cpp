
//#include "LinkedList.h"
#include "Board.h"
#include "Player.h"
#include "Tile.h"

#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>


#define EXIT_SUCCESS    0

void mainMenu();
void playGame(std::vector<Player*> playerNames, int* playerID, Board* board);
std::vector<Player*> addPlayers(std::vector<Player*> playerNames, std::string player);
Board checkCommand(std::string command, Board board, std::vector<PlacedTile>* tilesPlaced, std::vector<Player*>* playerNames, int playerID, std::set<Tile*>* tilesPoints, bool* savedGame);
bool checkName(std::string name);
void fileExists(std::string fileName, std::vector<Player*>* playerNames, int* playerID);
int changeCharToInt(char charToChange);
bool validateTilePlacement(std::vector<PlacedTile> tilesPlaced, Board* board);
Board placeTile(std::vector<std::string> tokens, std::vector<PlacedTile>* tilesPlaced, Board board, std::vector<Player*>* playerNames, int playerID, std::set<Tile*>* tilesPoints);
void points(std::set<Tile*> tilesPoints, Board* board, std::vector<Player*>* playerNames, int playerID, int row, int col, Tile* tile);

int main(void) {
   mainMenu();
   return EXIT_SUCCESS;
}

void mainMenu(){
   while (true){
       int menuSelection = 0;
      std::cout << "Welcome To Scrabble!" << std::endl;
      std::cout << "-------------------" << std::endl;
      std::cout << "Menu" << std::endl;
      std::cout << "----" << std::endl;
      std::cout << "1. New Game" << std::endl;
      std::cout << "2. Load Game" << std::endl;
      std::cout << "3. Credits" << std::endl;
      std::cout << "4. Quit" << std::endl;
      
      //menuSelection = std::cin.get();
      //getline(std::cin, menuSelection);
      std::cin >> menuSelection;
      if(!std::cin.eof()){
         if(menuSelection == 1){ //play game option
            std::vector<Player*> playerNames;
            //playerNames.resize(2);            
            std::cout << std::endl;
            std::cout << "Starting a New Game" << std::endl;
            std::cout<<std::endl;
            std::string message;
            getline(std::cin, message);
            playerNames = addPlayers(playerNames, "1");
            std::cin.clear(); //allows for multiple inputs
            std::cin.sync();
            playerNames = addPlayers(playerNames, "2");
            std::cout << std::endl;
            std::cout << "Player 1: " << playerNames[0]->getName() << ", " << playerNames[0]->getPoints() << std::endl;
            std::cout << "Player 2: " << playerNames[1]->getName() << ", " << playerNames[1]->getPoints() << std::endl;
            std::cout << std::endl;            
            std::cout << "Lets Play!" << std::endl;
            std::cout << std::endl;
            int playerID = 0;
            Board board = Board();
            playGame(playerNames, &playerID, &board);
         }else if(menuSelection == 2){ //load game option
            std::vector<Player*> playerNames;
            int playerID = 0;
            std::cin.clear();
            std::cin.sync();
            std::cout << std::endl;
            std::cout << "Enter the filename from which load a game" << std::endl;
            std::string fileName;
            getline(std::cin, fileName);// name of file
            getline(std::cin, fileName);// name of file
            fileExists(fileName, &playerNames, &playerID); //checks if file exists
            std::cout << std::endl;         
            
         }else if(menuSelection == 3){ //prints name, id and email of group members
            std::cout << "----------------------------------" << std::endl;
            std::cout << "Name: Zain Haider Bangash" << std::endl;
            std::cout << "Student ID: s3817403" << std::endl;
            std::cout << "Email: s3817403@student.rmit.edu.au" << std::endl;
            std::cout << std::endl;
            std::cout << "Name: Tania" << std::endl;
            std::cout << "Student ID: s3821922" << std::endl;
            std::cout << "Email: s3821922@student.rmit.edu.au" << std::endl;
            std::cout << std::endl;
            std::cout << "Name: Mark Forcina" << std::endl;
            std::cout << "Student ID: s9971085" << std::endl;
            std::cout << "Email: s9971085@rmit.edu.au" << std::endl;
             std::cout << std::endl;
            std::cout << "Name: Christopher Tait" << std::endl;
            std::cout << "Student ID: s38899475" << std::endl;
            std::cout << "Email: s38899475@student.rmit.edu.au" << std::endl;
            std::cout << "----------------------------------" << std::endl;
            std::cout << std::endl;
         }else if(menuSelection == 4){//stop the program
            std::cout << "Good Bye" << std::endl;
            break;
         }
         else{ //if the input is invalid
            std::cin.clear();
            std::cin.sync();
            std::cout << std::endl;
            std::cout<<"Invalid input"<<std::endl;
            std::cout << std::endl;
            menuSelection = (int) getchar();

         }
      }
      else{
         break;
      }
   }
}

void playGame(std::vector<Player*> playerNames, int* playerID, Board* board){//scrabble
   std::string command;
   
   board->printBoard();
   std::vector<PlacedTile> tilesPlaced; //tiles placed by a player in a turn
   std::set<Tile*> tilesPoints;//tiles for which points have been given
   while(true){
      std::cout<<"Enter command: ";
      getline(std::cin, command);
      if(command.empty() == false){
         if (command == "pass"){ //switches playerID 
            if(*playerID == 0){ 
               *playerID = 1;
               tilesPlaced.clear(); //empties vector
               tilesPoints.clear();
            }else{
               *playerID = 0;
               tilesPlaced.clear();
               tilesPoints.clear();
            }
         }else{
            bool savedGame = false;
            *board = checkCommand(command, *board, &tilesPlaced, &playerNames, *playerID, &tilesPoints, &savedGame); //validates command and acts accordingly
            if(savedGame == true){
               std::cout<<std::endl;
               std::cout<<"Game saved successfully" << std::endl;
               std::cout<<std::endl;
               break;
            }else{
               board->printBoard(); //prints board
            }
         }
      }
   }
   
}

std::vector<Player*> addPlayers(std::vector<Player*> playerNames, std::string player){ //adds Player names
   bool validPlayer = false;
   while (validPlayer == false){
      std::cin.clear(); //allows for multiple inputs
      std::cin.sync();
      std::cout << "Enter a name for player "<<  player <<" (uppercase characters only)" << std::endl;
      std::string name;
      getline(std::cin, name);  //player 1 name input
      if(checkName(name)==true){
         validPlayer = true;
         playerNames.push_back(new Player(name, 0)); //add player 1 name to playerNames vector
      }
      std::cout << std::endl;
   }
   return playerNames;
}

void fileExists(std::string fileName, std::vector<Player*>* playerNames, int* playerID){//checks if file exists
   Board board = Board();
   int row = 0;
   int col = 0;
   std::ifstream myfile;
   std::string data;
   myfile.open(fileName); //opens file
   int line = 1;
   if(myfile) { //if return true file exists
      getline(myfile, data);
      while ( !myfile.eof() ) { // keep reading until end-of-file
         if(line == 1 || line == 3){
            Player* player = new Player(data, 0);
            playerNames->push_back(player);
         }else if(line == 2 || line == 4){
            if (line == 2){
               playerNames->at(0)->setPoints(std::stoi(data));
            }else{
               playerNames->at(1)->setPoints(std::stoi(data));
            }
         }else if(line > 6 && line < 22){
            std::string substring  = data.substr(4, 61);
            for(std::__cxx11::basic_string<char>::size_type f = 0; f < substring.size(); f++){
               if(row < BOARD_SIZE){
                  if(f%4 == 0){
                     if(substring.at(f)!=' '){
                        Tile* tile = new Tile(substring.at(f), 1);
                        board.setTile(tile, row, col);
                     }
                     col++;
                  }
               }
            }
            row++;
            col = 0;
         }else if(line == 22){
            if(playerNames->at(0)->getName() == data){
               *playerID = 0;
            }else{
               *playerID = 1;
            }
         }
         //cout << "The next line is " << data << endl;
         getline(myfile, data); // sets EOF flag if no value found
         line++;

      }
      myfile.close();
      playGame(*playerNames, playerID, &board);
   } else { //else file doesnt exist
      std::cout<<"File Doesn't Exist" << std::endl;
   }
}

bool checkName(std::string name){ //validates names
   bool validName = true;
	for (std::__cxx11::basic_string<char>::size_type i = 0; i < name.size(); i++)
	{
		if (((int)(name[i]) < 65 || (int)(name[i]) > 90) && (int)(name[i]) != 32) //checks for ascii number of capital letter and ignores spaces
        {                                                                      //if it contains anything but capital letters or space returns false
            validName = false;
        }
	}
	
    if (validName == false){ //if name is false then prints the following message
        std::cout << "invalid name, name should be uppercase and contain only letters" << std::endl;
        std::cout<<std::endl;
    }
    return validName;
}

int changeCharToInt(char charToChange){//change char to int for the row 
   if(charToChange == 'A'){
      return 0;
   }else if(charToChange == 'B'){
      return 1;
   }else if(charToChange == 'C'){
      return 2;
   }else if(charToChange == 'D'){
      return 3;
   }else if(charToChange == 'E'){
      return 4;
   }else if(charToChange == 'F'){
      return 5;
   }else if(charToChange == 'G'){
      return 6;
   }else if(charToChange == 'H'){
      return 7;
   }else if(charToChange == 'I'){
      return 8;
   }else if(charToChange == 'J'){
      return 9;
   }else if(charToChange == 'K'){
      return 10;
   }else if(charToChange == 'L'){
     return 11;
   }else if(charToChange == 'M'){
      return 12;
   }else if(charToChange == 'N'){
      return 13;
   }else if(charToChange == 'O'){
      return 14;
   }else{
      return 0;
   }
}

Board placeTile(std::vector<std::string> tokens, std::vector<PlacedTile>* tilesPlaced, Board board, std::vector<Player*>* playerNames, int playerID, std::set<Tile*>* tilesPoints){
   std::string column;
   column.push_back(tokens[3].at(1));
   if(tokens[3].size() == 3){
      column.push_back(tokens[3].at(2));
   }
   int columnInt = std::stoi(column) - 1;
   int rowInt = changeCharToInt(tokens[3].at(0));
   // delete
   Tile *tile = new Tile(tokens[1].at(0), 1);
   // delete
   struct PlacedTile placeTile;
   placeTile.tile = tile;
   placeTile.x = columnInt;
   placeTile.y = rowInt;
   tilesPlaced->push_back(placeTile);
   if (validateTilePlacement(*tilesPlaced, &board))
   { // check if tile can be placed
      board.setTile(tile, rowInt, columnInt);
      tilesPoints->insert(tile);
      points(*tilesPoints, &board, playerNames, playerID, rowInt, columnInt, tile);
      if (tilesPlaced->size() == 7)
      { // prints BINGO if user places 7 tiles
         std::cout << "BINGO!" << std::endl;
         playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + 50);
         std::cout << "Player: " << playerNames->at(playerID)->getName() << ", points: " << playerNames->at(playerID)->getPoints() << std::endl;
      }
      return board;
   }
   else
   {
      tilesPlaced->pop_back(); // removes if validateTilePlacement fails
      return board;
   }
}

void points(std::set<Tile*> tilesPoints, Board* board, std::vector<Player*>* playerNames, int playerID, int row, int col, Tile* tile){
   //check tiles to the right, lefy, above and below
   playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + tile->value);
   int right = 1;
   int left = 1;
   int above = 1;
   int below = 1;
   for (int i = 0; i < BOARD_SIZE; i++) {
      if(col + right < BOARD_SIZE){
         if (tilesPoints.find(board->getTile(row, col+1)) != tilesPoints.end()){}
         else{
            if((board->getTile(row, col+right) != nullptr)){
               playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + board->getTile(row, col+right)->value); 
               right++;
               std::cout<< "RIGHT Player: " << playerNames->at(playerID)->getName() << ", " << playerNames->at(playerID)->getPoints()<<std::endl;
            }
         }
      }
      if(col - left >= 0){
         if (tilesPoints.find(board->getTile(row, col-1)) != tilesPoints.end()){}
         else{
            if(board->getTile(row, col-left) != nullptr ){
               playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + board->getTile(row, col-left)->value); 
               left++;
               std::cout<< "LEFT Player: " << playerNames->at(playerID)->getName() << ", " << playerNames->at(playerID)->getPoints() <<std::endl;
            }
         }
      }
      if(row + below < BOARD_SIZE){
         if (tilesPoints.find(board->getTile(row+1, col)) != tilesPoints.end()){}
         else{
            if(board->getTile(row+below, col) != nullptr ){
               playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + board->getTile(row+below, col)->value); 
               below++;
               std::cout<< "BELOW Player: " << playerNames->at(playerID)->getName() << ", " << playerNames->at(playerID)->getPoints()<<std::endl;
            }
         }
      }
      if(row - above >= 0){
         if (tilesPoints.find(board->getTile(row-1, col)) != tilesPoints.end()){}
         else{
            if(board->getTile(row-above, col) != nullptr){
               playerNames->at(playerID)->setPoints(playerNames->at(playerID)->getPoints() + board->getTile(row-above, col)->value); 
               above++;
               std::cout<< "ABOVE Player: " << playerNames->at(playerID)->getName() << ", " << playerNames->at(playerID)->getPoints()<<std::endl;
            }
         }
      }
   }
}

Board checkCommand(std::string command, Board board, std::vector<PlacedTile>* tilesPlaced,std::vector<Player*>* playerNames, int playerID,std::set<Tile*>* tilesPoints, bool* savedGame){ //validates command
   //bool validCommand = true;
   std::string inter;
   std::vector<std::string> tokens;
   std::stringstream check1(command);
   while(getline(check1, inter, ' ')){ //tokenizes command string
      tokens.push_back(inter);
   }
   if(tokens[0]=="place"){ //if first word is place
      std::string rows = "ABCDEFGHIJKLMNO";
      //check if tile is in hand
      
      if(tokens[2]!="at"){ // if second word isnt "at"
         std::cout<<"Place command error at 'at' "<<std::endl;
      }else{
         if((rows.find(tokens[3].at(0)) != std::string::npos)){ //if the row coordinate is valid
            if(tokens[3].size() == 2){ // if column number is single digit
               if(tokens[3].at(1) == '1' ||tokens[3].at(1) == '2' || tokens[3].at(1) == '3' ||tokens[3].at(1) == '4' ||tokens[3].at(1) == '5'|| tokens[3].at(1) == '6' ||tokens[3].at(1) == '7' ||tokens[3].at(1) == '8'|| tokens[3].at(1) == '9' ){
                  board = placeTile(tokens, tilesPlaced, board, playerNames, playerID, tilesPoints);
               }else{
               std::cout << "Place command error at grid coordinates" << std::endl;
            }
            }else if(tokens[3].size() == 3){// if column number is single digit
               if((tokens[3].at(1) == '1') &(tokens[3].at(2) == '0' ||tokens[3].at(2) == '1'|| tokens[3].at(2) == '2' ||tokens[3].at(2) == '3' ||tokens[3].at(2) == '4'|| tokens[3].at(2) == '5')){
                  board = placeTile(tokens, tilesPlaced, board, playerNames, playerID, tilesPoints);
               }
            }else{
               std::cout << "Place command error at grid coordinates" << std::endl;
            }
         }else{
            //validCommand = false;
            std::cout << "Place command error at grid coordinates" << std::endl;
         }
      }
   }else if(tokens[0]=="replace"){ // if first word is replace
      std::string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      
      if(!alphabets.find(tokens[2])){//CHECK IF TILE IS IN HAND
         //validCommand = false;
      }else{
         std::cout << "replace Valid" << std::endl;
      }
   }else if(tokens[0]=="save"){ //saves game info in file
      std::ofstream myfile;
      if(tokens.size() == 2){
         myfile.open(tokens[1]);
         if(myfile) { //writes to file
            std::ofstream fileToOverWrite(tokens[1], std::ofstream::trunc);
            fileToOverWrite << playerNames->at(0)->getName() <<"\n";
            fileToOverWrite << playerNames->at(0)->getPoints() <<"\n";
            //print hand for player 1
            fileToOverWrite << playerNames->at(1)->getName() <<"\n";
            fileToOverWrite << playerNames->at(1)->getPoints() <<"\n";
            //print hand for player 2
            std::vector<std::string> rows = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"}; // rows
            fileToOverWrite<<"    1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  " <<"\n"; //print column headers
            fileToOverWrite<<"  ------------------------------------------------------------- " <<"\n"; 
            int i = 0;
            for (int row = 0; row < BOARD_SIZE; row++){
               fileToOverWrite<< rows[i] << " | "; //print row headers
               i++;
               for (int col = 0; col < BOARD_SIZE; col++){   
                  if (board.getTile(row, col) == nullptr){
                    fileToOverWrite <<"  | ";
                  }
                  else{
                    fileToOverWrite << board.getTile(row, col)->getLetter() << " | ";//print board contents
                  }
               }
               fileToOverWrite << "\n";
            }

            
            //print tile bag contents
            fileToOverWrite << playerNames->at(playerID)->getName();
            fileToOverWrite.close();
         }
         myfile.close();
         *savedGame = true;
      }else{
         std::cout<<"Save command error"<<std::endl;
         std::cout<<std::endl;
      }
      
   }else{
      std::cout << "Invalid Command" << std::endl;
   }
   return board;

}

bool validateTilePlacement(std::vector<PlacedTile> tilesPlaced, Board* board) {
    bool valid = true;

    // check tiles are not placed on top of one another
    if(board->tileExists(tilesPlaced.at(tilesPlaced.size()-1).x, tilesPlaced.at(tilesPlaced.size()-1).y)){
       valid = false;
       std::cout<<"Can't place a tile on another tile"<<std::endl;
    }

    // check all tiles placed are in the same row or column
   if (tilesPlaced.size() > 1) {
      int row = tilesPlaced[0].y;
      int col = tilesPlaced[0].x;

      if (row == tilesPlaced[1].y) {
         for (PlacedTile t : tilesPlaced) {
            if (t.y != row) {
               valid = false;
               std::cout<<"Tile has to be in the same row"<<std::endl;
            }
         }
      } else {
            for (PlacedTile t : tilesPlaced) {
                if (t.x != col) {
                    valid = false;
                    std::cout<<"Tile has to be in the same row"<<std::endl;
                }
            }
        }
   }

    return valid;

}

