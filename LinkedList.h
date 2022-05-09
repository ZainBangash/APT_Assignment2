
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

#include <iostream>

using std::cout;
using std::endl;

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();

   Tile* get(int index);
   void add_front(Tile* tile);
   void add_back(Tile* tile);
   void remove_front();
   void remove_back();
   void remove(int index);
   void clear();

   void add_front(Tile* data);
   void add_back(Tile* data);

   void remove_front();
   void remove_back();

   void remove(int index);

   void clear();   

private:
   Node* head;
};


#endif // ASSIGN2_LINKEDLIST_H
