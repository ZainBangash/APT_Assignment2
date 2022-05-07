
//#include "LinkedList.h"
#include "Board.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>


#define EXIT_SUCCESS    0

void mainMenu();
void playGame(std::vector<Player*> playerNames);
std::vector<Player*> addPlayers(std::vector<Player*> playerNames, std::string player);
Board checkCommand(std::string command, Board board);
bool checkName(std::string name);
bool fileExists(std::string fileName);
int changeCharToInt(char charToChange);

int main(void) {
  // LinkedList* list = new LinkedList();
   //delete list;
   std::string command;
   Board board = Board();
   board.printBoard();
   while(true){
      std::cout<<"Enter command: ";
      getline(std::cin, command);
      board = checkCommand(command, board);
      board.printBoard();
   }
   

   //std::cout.flush();   
   //mainMenu();
   return EXIT_SUCCESS;
}

void mainMenu(){
   int menuSelection;
   while (true){
      std::cout << "Welcome To Scrabble!" << std::endl;
      std::cout << "-------------------" << std::endl;
      std::cout << "Menu" << std::endl;
      std::cout << "----" << std::endl;
      std::cout << "1. New Game" << std::endl;
      std::cout << "2. Load Game" << std::endl;
      std::cout << "3. Credits" << std::endl;
      std::cout << "4. Quit" << std::endl;
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
         }else if(menuSelection == 2){ //load game option
            std::cin.clear();
            std::cin.sync();
            std::cout << std::endl;
            std::cout << "Enter the filename from which load a game" << std::endl;
            std::string fileName;
            getline(std::cin, fileName);// name of file
            fileExists(fileName); //checks if file exists
            std::cout << std::endl;         
         }else if(menuSelection == 3){ //prints name, id and email of group members
            std::cout << "----------------------------------" << std::endl;
            std::cout << "Name: Zain Haider Bangash" << std::endl;
            std::cout << "Student ID: s3817403" << std::endl;
            std::cout << "Email: s3817403@student.rmit.edu.au" << std::endl;
            std::cout << std::endl;
            std::cout << "Name: Tania" << std::endl;
            std::cout << "Student ID: ID" << std::endl;
            std::cout << "Email: email" << std::endl;
            std::cout << std::endl;
            std::cout << "Name: Mark" << std::endl;
            std::cout << "Student ID: ID" << std::endl;
            std::cout << "Email: email" << std::endl;
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
            std::cout<<"Invalid output"<<std::endl;
            std::cout << std::endl;

         }
      }
      else{
         break;
      }
   }
}

void playGame(std::vector<Player*> playerNames){
   Board board = Board();
   board.printBoard();
   
   
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


bool fileExists(std::string fileName){//checks if file exists
   std::ifstream myfile;
   myfile.open(fileName); //opens file
   if(myfile) { //if return true file exists
      std::cout<<"File Exists"<<std::endl;
      return true;
   } else { //else file doesnt exist
      std::cout<<"File Doesn't Exist" << std::endl;
      return false;
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

int changeCharToInt(char charToChange){
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


Board checkCommand(std::string command, Board board){ //validates command
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
      
      if(tokens[2]!="at"){
         //validCommand = false;
         std::cout<<"Place command error at 'at' "<<std::endl;
      }else{
         if((rows.find(tokens[3].at(0)) != std::string::npos)){
            if(tokens[3].size() == 2){
               if(tokens[3].at(1) == '1' ||tokens[3].at(1) == '2' || tokens[3].at(1) == '3' ||tokens[3].at(1) == '4' ||tokens[3].at(1) == '5'|| tokens[3].at(1) == '6' ||tokens[3].at(1) == '7' ||tokens[3].at(1) == '8'|| tokens[3].at(1) == '9' ){
                  std::string column;
                  column.push_back(tokens[3].at(1));
                  int columnInt = std::stoi(column)-1;
                  int rowInt = changeCharToInt(tokens[3].at(0));
                  //delete
                  Tile* tile = new Tile(tokens[1].at(0), 0);
                  //delete
                  board.setTile(tile, rowInt, columnInt);
               }
            }else if(tokens[3].size() == 3){
               if((tokens[3].at(1) == '1') &(tokens[3].at(2) == '0' ||tokens[3].at(2) == '1'|| tokens[3].at(2) == '2' ||tokens[3].at(2) == '3' ||tokens[3].at(2) == '4'|| tokens[3].at(2) == '5')){
                  std::string column;
                  column.push_back(tokens[3].at(1));
                  column.push_back(tokens[3].at(2));
                  int columnInt = std::stoi(column)-1;
                  int rowInt = changeCharToInt(tokens[3].at(0));
                  //delete
                  Tile* tile = new Tile(tokens[1].at(0), 0);
                  //delete
                  board.setTile(tile, rowInt, columnInt);
               }
            }else{
               //validCommand = false;
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
   }else if(tokens[0]=="pass"){ // passes turn
   }else if(tokens[0]=="save"){ //saves game info in file
      std::ifstream myfile;
      myfile.open(tokens[1]);
      if(myfile) { //if file exists it overwrites file
         std::ofstream fileToOverWrite(tokens[1], std::ofstream::trunc);
         fileToOverWrite << "OverWriting Existing File";
      }else{ //writes in file 
         std::ofstream fileToWrite(tokens[1]);
         fileToWrite << "Files can be tricky, but it is fun enough!";
         fileToWrite.close();
      }
      myfile.close();
   }else{
      std::cout << "Invalid Command" << std::endl;
   }
   return board;

}

