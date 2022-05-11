#include "Scrabble.h"


Scrabble::Scrabble(string tileFile) {
    tileBag = TileBag();

    ifstream is;
    is.open("ScrabbleTiles.txt");

    tileBag.loadTiles(is);
    tileBag.shuffleTiles();

    cout << "HEREE" << tileBag.popTile()->value << endl;

    board = Board();

    currentPlayer = 0;
}

Scrabble::~Scrabble() {
}


void Scrabble::run() {
    //cout.flush();
    mainMenu();
}


void Scrabble::mainMenu(){
   string menuSelection = "";
   while (true){
      cout << "Welcome To Scrabble!" << endl;
      cout << "-------------------" << endl;
      cout << "Menu" << endl;
      cout << "----" << endl;
      cout << "1. New Game" << endl;
      cout << "2. Load Game" << endl;
      cout << "3. Credits" << endl;
      cout << "4. Quit" << endl;
      getline(cin, menuSelection);
      if(!cin.eof()){
         if(menuSelection == "1"){ //play game option

            cout << endl;
            cout << "Starting a New Game" << endl;
            cout<<endl;
            addPlayer(1);
            addPlayer(2);
            cout << endl;
            cout << "Player 1: " << players[0]->getName() << ", " << players[0]->getPoints() << endl;
            cout << "Player 2: " << players[1]->getName() << ", " << players[1]->getPoints() << endl;
            cout << endl;
            cout << "Lets Play!" << endl;
            cout << endl;
            playGame();

         }else if(menuSelection == "2"){ //load game option
            cout << endl;
            cout << "Enter the filename from which load a game" << endl;
            string fileName;
            getline(cin >> std::ws, fileName);// name of file
            loadGame(fileName);
            cout << endl;

         }else if(menuSelection == "3"){ //prints name, id and email of group members
            cout << "----------------------------------" << endl;
            cout << "Name: Zain Haider Bangash" << endl;
            cout << "Student ID: s3817403" << endl;
            cout << "Email: s3817403@student.rmit.edu.au" << endl;
            cout << endl;
            cout << "Name: Tania" << endl;
            cout << "Student ID: ID" << endl;
            cout << "Email: email" << endl;
            cout << endl;
            cout << "Name: Mark" << endl;
            cout << "Student ID: ID" << endl;
            cout << "Email: email" << endl;
            cout << endl;
            cout << "Name: Christopher Tait" << endl;
            cout << "Student ID: s3899475" << endl;
            cout << "Email: s3899475@student.rmit.edu.au" << endl;
            cout << "----------------------------------" << endl;
            cout << endl;

         }else if(menuSelection == "4"){//stop the program
            cout << "Good Bye" << endl;
            break;
         }
         else{ //if the input is invalid
            cin.clear();
            cin.sync();
            cout << endl;
            cout<<"Invalid input"<<endl;
            cout << endl;

         }
      }
      else{
         break;
      }
   }
}

void Scrabble::playGame(){//scrabble
   string command;
   board.printBoard();
   vector<PlacedTile> tilesPlaced; //tiles placed by a player in a turn
   set<Tile*> tilesPoints;//tiles for which points have been given
   while(true){
       // remove
      players[currentPlayer]->printHand();
      cout<<"Enter command: ";
      getline(cin, command);
      if(command.empty() == false){
         if (command == "pass"){ //switches currentPlayer
            if(currentPlayer == 0){
                // renew player hand
                for (uint i = 0; i < tilesPlaced.size(); i++) {
                    //cout << "tilesLeft " << tileBag.tilesLeft();
                    if (tileBag.tilesLeft() > 0) {
                        players[currentPlayer]->addTileToHand(tileBag.popTile());
                    }
                }

                currentPlayer = 1;
                tilesPlaced.clear(); //empties vector
                tilesPoints.clear();

            }else{
                for (uint i = 0; i < tilesPlaced.size(); i++) {
                    //cout << "tilesLeft " << tileBag.tilesLeft();
                    if (tileBag.tilesLeft() > 0) {
                        players[currentPlayer]->addTileToHand(tileBag.popTile());
                    }
                }

                currentPlayer = 0;
                tilesPlaced.clear();
                tilesPoints.clear();

            }
         }else{
            bool savedGame = false;
            checkCommand(command, &tilesPlaced, &tilesPoints, &savedGame); //validates command and acts accordingly
            if(savedGame == true){
               cout<<endl;
               cout<<"Game saved successfully" << endl;
               cout<<endl;
               break;
            }else{
               board.printBoard(); //prints board
            }
         }
      }
   }

}


void Scrabble::addPlayer(int playerNum){ //adds Player names
   //cin.clear(); //allows for multiple inputs
   //cin.sync();
   cout << "Enter a name for player "<<  playerNum <<" (uppercase characters only)" << endl;
   string playerName;
   getline(cin, playerName);  //player 1 name input
   if(checkName(playerName)==true){
       Player* p = new Player(playerName, playerNum, &board);
        for (int i = 0; i < HAND_SIZE; i++) {
            p->addTileToHand(tileBag.popTile());
        }
      players.push_back(p);
   }
   cout << endl;
}


void Scrabble::loadGame(string fileName){//checks if file exists
   Board board = Board();
   int row = 0;
   int col = 0;
   ifstream myfile;
   string data;
   myfile.open(fileName); //opens file
   int line = 1;
   int id = 0;
   if(myfile) { //if return true file exists
      getline(myfile, data);
      while ( !myfile.eof() ) { // keep reading until end-of-file
         if(line == 1 || line == 3){
            players.push_back(new Player(data, id, &board));
            ++id;
         }else if(line == 2 || line == 4){
            if (line == 2){
               players.at(0)->setPoints(stoi(data));
            }else{
               players.at(1)->setPoints(stoi(data));
            }
         }else if(line > 6 && line < 22){
            std::string substring  = data.substr(4, 61);
            for(std::__cxx11::basic_string<char>::size_type f = 0; f < substring.size(); f++){
               if(row < BOARD_SIZE){
                  if(f%4 == 0){
                     if(substring.at(f)!=' '){
                        Tile* tile = new Tile(substring.at(f), 1);
                        board.setTile(col, row, tile);
                     }
                     col++;
                  }
               }
            }
            row++;
            col = 0;
         }else if(line == 22){
            if(players.at(0)->getName() == data){
               currentPlayer = 0;
            }else{
               currentPlayer = 1;
            }
         }
         //cout << "The next line is " << data << endl;
         getline(myfile, data); // sets EOF flag if no value found
         line++;

      }
      myfile.close();
      playGame();
   } else { //else file doesnt exist
      std::cout<<"File Doesn't Exist" << std::endl;
   }
}


bool Scrabble::checkName(string name){ //validates names
    bool validName = true;
    for (std::__cxx11::basic_string<char>::size_type i = 0; i < name.size(); i++)
    {
        if (((int)(name[i]) < 65 || (int)(name[i]) > 90) && (int)(name[i]) != 32) //checks for ascii number of capital letter and ignores spaces
        {                                                                      //if it contains anything but capital letters or space returns false
            validName = false;
        }
    }

    if (validName == false){ //if name is false then prints the following message
        cout << "invalid name, name should be uppercase and contain only letters" << endl;
    }
    return validName;
}

void Scrabble::placeTile(vector<string> tokens, vector<PlacedTile>* tilesPlaced, set<Tile*>* tilesPoints){
   string column;
   column.push_back(tokens[3].at(1));
   if(tokens[3].size() == 3){
      column.push_back(tokens[3].at(2));
   }
   int columnInt = stoi(column) - 1;
   // convert from upper case alphabet to row int
   int rowInt = tokens[3].at(0) - 65;
   // check if the player has the tile in their hand
   if (players[currentPlayer]->hasTile(tokens[1].at(0))) {
       struct PlacedTile placeTile;
       placeTile.tile = players[currentPlayer]->getTile(tokens[1].at(0));
       placeTile.x = columnInt;
       placeTile.y = rowInt;
       tilesPlaced->push_back(placeTile);
       // validate that the player has the right tiles
       if (validateTilePlacement(*tilesPlaced)) {
          // check if tile can be placed
          // remove tiles from hand
          players[currentPlayer]->removeTile(tokens[1].at(0));
          board.setTile(columnInt, rowInt, placeTile.tile);
          tilesPoints->insert(placeTile.tile);
          points(*tilesPoints, rowInt, columnInt, placeTile.tile);
          if (tilesPlaced->size() == 7)
          { // prints BINGO if user places 7 tiles
             cout << "BINGO!" << endl;
             players.at(currentPlayer)->addPoints( + 50);
             cout << "Player: " << players.at(currentPlayer)->getName() << ", points: " << players.at(currentPlayer)->getPoints() << endl;
          }
       } else {
          tilesPlaced->pop_back(); // removes if validateTilePlacement fails
       }
    }
}


void Scrabble::points(set<Tile*> tilesPoints, int row, int col, Tile* tile){
   //check tiles to the right, lefy, above and below
   players.at(currentPlayer)->addPoints(tile->value);
   int right = 1;
   int left = 1;
   int above = 1;
   int below = 1;
   for (int i = 0; i < BOARD_SIZE; i++) {
      if(col + right < BOARD_SIZE){
         if (tilesPoints.find(board.getTile(row, col+1)) != tilesPoints.end()){}
         else{
            if((board.getTile(row, col+right) != nullptr)){
               players.at(currentPlayer)->addPoints(board.getTile(row, col+right)->value);
               right++;
               cout<< "RIGHT Player: " << players.at(currentPlayer)->getName() << ", " << players.at(currentPlayer)->getPoints()<<endl;
            }
         }
      }
      if(col - left >= 0){
         if (tilesPoints.find(board.getTile(row, col-1)) != tilesPoints.end()){}
         else{
            if(board.getTile(row, col-left) != nullptr ){
               players.at(currentPlayer)->addPoints(board.getTile(row, col-left)->value);
               left++;
               cout<< "LEFT Player: " << players.at(currentPlayer)->getName() << ", " << players.at(currentPlayer)->getPoints() <<endl;
            }
         }
      }
      if(row + below < BOARD_SIZE){
         if (tilesPoints.find(board.getTile(row+1, col)) != tilesPoints.end()){}
         else{
            if(board.getTile(row+below, col) != nullptr ){
               players.at(currentPlayer)->addPoints(board.getTile(row+below, col)->value);
               below++;
               cout<< "BELOW Player: " << players.at(currentPlayer)->getName() << ", " << players.at(currentPlayer)->getPoints()<<endl;
            }
         }
      }
      if(row - above >= 0){
         if (tilesPoints.find(board.getTile(row-1, col)) != tilesPoints.end()){}
         else{
            if(board.getTile(row-above, col) != nullptr){
               players.at(currentPlayer)->addPoints(board.getTile(row-above, col)->value);
               above++;
               cout<< "ABOVE Player: " << players.at(currentPlayer)->getName() << ", " << players.at(currentPlayer)->getPoints()<<endl;
            }
         }
      }
   }
}


void Scrabble::checkCommand(string command, vector<PlacedTile>* tilesPlaced, set<Tile*>* tilesPoints, bool* savedGame){ //validates command
   //bool validCommand = true;
   string inter;
   vector<string> tokens;
   stringstream check1(command);
   while(getline(check1, inter, ' ')){ //tokenizes command string
      tokens.push_back(inter);
   }
   if(tokens[0]=="place"){ //if first word is place
      string rows = "ABCDEFGHIJKLMNO";

      if(tokens[2]!="at"){ // if second word isnt "at"
         cout<<"Place command error at 'at' "<<endl;
      }else{
         if((rows.find(tokens[3].at(0)) != string::npos)){ //if the row coordinate is valid
            if(tokens[3].size() == 2){ // if column number is single digit
               if(tokens[3].at(1) == '1' ||tokens[3].at(1) == '2' || tokens[3].at(1) == '3' ||tokens[3].at(1) == '4' ||tokens[3].at(1) == '5'|| tokens[3].at(1) == '6' ||tokens[3].at(1) == '7' ||tokens[3].at(1) == '8'|| tokens[3].at(1) == '9' ){
                  placeTile(tokens, tilesPlaced, tilesPoints);
               }else{
               cout << "Place command error at grid coordinates" << endl;
            }
            }else if(tokens[3].size() == 3){// if column number is single digit
               if((tokens[3].at(1) == '1') &(tokens[3].at(2) == '0' ||tokens[3].at(2) == '1'|| tokens[3].at(2) == '2' ||tokens[3].at(2) == '3' ||tokens[3].at(2) == '4'|| tokens[3].at(2) == '5')){
                  placeTile(tokens, tilesPlaced, tilesPoints);
               }
            }else{
               cout << "Place command error at grid coordinates" << endl;
            }
         }else{
            //validCommand = false;
            cout << "Place command error at grid coordinates" << endl;
         }
      }
   }else if(tokens[0]=="replace"){ // if first word is replace

      if(players[currentPlayer]->hasTile(tokens[1].at(0))){//CHECK IF TILE IS IN HAND
            players[currentPlayer]->replaceTile(tokens[1].at(0), tileBag.popTile());
      }else{
         cout << "you don't have that tile" << std::endl;
      }
   }else if(tokens[0]=="save"){ //saves game info in file
      ofstream myfile;
      if(tokens.size() == 2){
         myfile.open(tokens[1]);
         if(myfile) { //writes to file
            ofstream fileToOverWrite(tokens[1], ofstream::trunc);
            fileToOverWrite << players.at(0)->getName() <<"\n";
            fileToOverWrite << players.at(0)->getPoints() <<"\n";
            //print hand for player 1
            fileToOverWrite << players.at(1)->getName() <<"\n";
            fileToOverWrite << players.at(1)->getPoints() <<"\n";
            //print hand for player 2
            vector<string> rows = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"}; // rows
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
                    fileToOverWrite << board.getTile(row, col)->letter << " | ";//print board contents
                  }
               }
               fileToOverWrite << "\n";
            }


            //print tile bag contents
            fileToOverWrite << players.at(currentPlayer)->getName();
            fileToOverWrite.close();
         }
         myfile.close();
         *savedGame = true;
      }else{
         cout<<"Save command error"<<endl;
         cout<<endl;
      }

   }else{
      cout << "Invalid Command" << endl;
   }

}



bool Scrabble::validateTilePlacement(vector<PlacedTile> tilesPlaced) {
    bool valid = true;

    // check tiles are not placed on top of one another
    if(board.tileExists(tilesPlaced.at(tilesPlaced.size()-1).x, tilesPlaced.at(tilesPlaced.size()-1).y)){
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
                    std::cout<<"Tile has to be in the same col"<<std::endl;
                }
            }
        }
   }

    return valid;

}
