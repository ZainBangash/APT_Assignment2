//#include "LinkedList.h"
#include "Board.h"
#include "Tile.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>



#define EXIT_SUCCESS    0

void mainMenu();
bool addPlayers(std::vector<std::string> playerNames, std::string player);
bool checkCommand(std::string command);
bool checkName(std::string name);
bool fileExists(std::string fileName);

int main(void) {
    // LinkedList* list = new LinkedList();
    //delete list;
    //std::cout.flush();
    mainMenu();
    //Board b = Board();

    //b.setTile(0, 5, new Tile('Z', 10));
    //b.printBoard();

    //delete b;

    //Player p = Player(&b);
    //p.addTileToHand(new Tile('Z', 10));
    //cout << p.hasTile('Z') << endl;

   return EXIT_SUCCESS;
}

void mainMenu(){
   int menuSelection;
   while (true){
      static std::vector<std::string> playerNames;
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

            std::cout << std::endl;
            std::cout << "Starting a New Game" << std::endl;
            std::cout<<std::endl;
            std::string message;
            getline(std::cin, message);
            addPlayers(playerNames, std::to_string(1));
            std::cin.clear(); //allows for multiple inputs
            std::cin.sync();
            addPlayers(playerNames, "2");
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

bool addPlayers(std::vector<std::string> playerNames, std::string player){ //adds Player names
   bool validPlayer = true;
   std::cin.clear(); //allows for multiple inputs
   std::cin.sync();
   std::cout << "Enter a name for player "<<  player <<" (uppercase characters only)" << std::endl;
   std::string name1;
   getline(std::cin, name1);  //player 1 name input
   if(checkName(name1)==true){
      playerNames.push_back(name1); //add player 1 name to playerNames vector
   }
   std::cout << std::endl;
   // std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   // std::string name2;
   // getline(std::cin, name2); // player 2 name input
   // checkName(name2);
   // if(checkName(name2)==true){
   //    playerNames.push_back(name2); // add player 2 name to playerNames vector
   // }
   return validPlayer;
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
    }
    return validName;
}

bool checkCommand(std::string command){ //validates command
   //bool validCommand = true;
   std::string inter;
   std::vector<std::string> tokens;
   //getline(std::cin, command);
   std::stringstream check1(command);
   //hardcode rows and columns
   //getline find out
   while(getline(check1, inter, ' ')){ //tokenizes command string
      tokens.push_back(inter);
   }
   if(tokens[0]=="place"){ //if first word is place
      std::string rows = "ABCDEF";
      //check if tile is in hand
      if(tokens[2]!="at"){
         //validCommand = false;
         std::cout<<"Place command error at 'at' "<<std::endl;
      }if((rows.find(tokens[3].at(0)) != std::string::npos)){
         std::cout << "Row valid" << std::endl;
         if(tokens[3].at(1) == '0' ||tokens[3].at(1) == '1' ||tokens[3].at(1) == '2' || tokens[3].at(1) == '3' ||tokens[3].at(1) == '4' ||tokens[3].at(1) == '5'){
            std::cout << " Column valid" << std::endl;
         }
      }else{
         std::cout << "Place command error at grid coordinates" << std::endl;

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
   return true;

}
