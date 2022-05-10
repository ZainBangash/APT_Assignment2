#include "Scrabble.h"


Scrabble::Scrabble(string tileFile) {
    tileBag = TileBag();

    ifstream is;
    is.open("ScrabbleTiles.txt");

    string s;
    getline(is, s);

    tileBag.loadTiles(is);
    tileBag.shuffleTiles();

    board = Board();
}

Scrabble::~Scrabble() {
}


void Scrabble::run() {
    //cout.flush();
    mainMenu();
}


void Scrabble::mainMenu(){
   int menuSelection;
   while (true){
      static vector<string> playerNames;
      cout << "Welcome To Scrabble!" << endl;
      cout << "-------------------" << endl;
      cout << "Menu" << endl;
      cout << "----" << endl;
      cout << "1. New Game" << endl;
      cout << "2. Load Game" << endl;
      cout << "3. Credits" << endl;
      cout << "4. Quit" << endl;
      cin >> menuSelection;
      if(!cin.eof()){
         if(menuSelection == 1){ //play game option

            cout << endl;
            cout << "Starting a New Game" << endl;
            cout<<endl;
            string message;
            getline(cin, message);
            addPlayer(1);
            cin.clear(); //allows for multiple inputs
            cin.sync();
            addPlayer(2);
            cout << endl;
            cout << "Lets Play!" << endl;
            cout << endl;
         }else if(menuSelection == 2){ //load game option
            cin.clear();
            cin.sync();
            cout << endl;
            cout << "Enter the filename from which load a game" << endl;
            string fileName;
            getline(cin, fileName);// name of file
            fileExists(fileName); //checks if file exists
            cout << endl;
         }else if(menuSelection == 3){ //prints name, id and email of group members
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
            cout << "----------------------------------" << endl;
            cout << endl;
            cout << "Name: Christopher Tait" << endl;
            cout << "Student ID: s3899475" << endl;
            cout << "Email: s3899475@student.rmit.edu.au" << endl;
            cout << "----------------------------------" << endl;
            cout << endl;

         }else if(menuSelection == 4){//stop the program
            cout << "Good Bye" << endl;
            break;
         }
         else{ //if the input is invalid
            cin.clear();
            cin.sync();
            cout << endl;
            cout<<"Invalid output"<<endl;
            cout << endl;

         }
      }
      else{
         break;
      }
   }
}

bool Scrabble::addPlayer(int playerNum){ //adds Player names
   bool validPlayer = true;
   cin.clear(); //allows for multiple inputs
   cin.sync();
   cout << "Enter a name for player "<<  playerNum <<" (uppercase characters only)" << endl;
   string playerName;
   getline(cin, playerName);  //player 1 name input
   if(checkName(playerName)==true){
      players.push_back(new Player(playerName, &board)); //add player 1 name to playerNames vector
   }
   cout << endl;
   // cout << "Enter a name for player 2 (uppercase characters only)" << endl;
   // string name2;
   // getline(cin, name2); // player 2 name input
   // checkName(name2);
   // if(checkName(name2)==true){
   //    playerNames.push_back(name2); // add player 2 name to playerNames vector
   // }
   return validPlayer;
}


bool Scrabble::fileExists(string fileName){//checks if file exists
   ifstream myfile;
   myfile.open(fileName); //opens file
   if(myfile) { //if return true file exists
      cout<<"File Exists"<<endl;
      return true;
   } else { //else file doesnt exist
      cout<<"File Doesn't Exist" << endl;
      return false;
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

bool checkCommand(string command){ //validates command
   //bool validCommand = true;
   string inter;
   vector<string> tokens;
   //getline(cin, command);
   stringstream check1(command);
   //hardcode rows and columns
   //getline find out
   while(getline(check1, inter, ' ')){ //tokenizes command string
      tokens.push_back(inter);
   }
   if(tokens[0]=="place"){ //if first word is place
      string rows = "ABCDEF";
      //check if tile is in hand
      if(tokens[2]!="at"){
         //validCommand = false;
         cout<<"Place command error at 'at' "<<endl;
      }if((rows.find(tokens[3].at(0)) != string::npos)){
         cout << "Row valid" << endl;
         if(tokens[3].at(1) == '0' ||tokens[3].at(1) == '1' ||tokens[3].at(1) == '2' || tokens[3].at(1) == '3' ||tokens[3].at(1) == '4' ||tokens[3].at(1) == '5'){
            cout << " Column valid" << endl;
         }
      }else{
         cout << "Place command error at grid coordinates" << endl;

      }
   }else if(tokens[0]=="replace"){ // if first word is replace
        //TODO HERE
      string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      if(!alphabets.find(tokens[2])){//CHECK IF TILE IS IN HAND
         //validCommand = false;
      }else{
         cout << "replace Valid" << endl;
      }
   }else if(tokens[0]=="pass"){ // passes turn
   }else if(tokens[0]=="save"){ //saves game info in file
      ifstream myfile;
      myfile.open(tokens[1]);
      if(myfile) { //if file exists it overwrites file
         ofstream fileToOverWrite(tokens[1], ofstream::trunc);
         fileToOverWrite << "OverWriting Existing File";
      }else{ //writes in file
         ofstream fileToWrite(tokens[1]);
         fileToWrite << "Files can be tricky, but it is fun enough!";
         fileToWrite.close();
      }
      myfile.close();
   }else{
      cout << "Invalid Command" << endl;
   }
   return true;

}
