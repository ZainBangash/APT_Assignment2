
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   int menuSelection = 0;
   std::cout << "Welcome To Scrabble!" << std::endl;
   std::cout << "-------------------" << std::endl;
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits" << std::endl;
   std::cout << "4. Quit" << std::endl;
   std::cin >> menuSelection;
   if(menuSelection != 1 || menuSelection != 2 || menuSelection != 3 || menuSelection != 4){
      std::cout<<"Invalid output"<<std::endl;
   }

   return EXIT_SUCCESS;
}
