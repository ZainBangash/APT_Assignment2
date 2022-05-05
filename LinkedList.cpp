#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
}

int LinkedList::size(){
    
    int length = 0;

    Node* current = head;
    while(current != nullptr){
        ++length;
        current = current->next;
    }
    return length;
}

Tile* LinkedList::get(int index){
    Tile* retTile = nullptr;

    if(index >= 0 && index < size()){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        retTile = current->tile;

    }
    return retTile;
}

void LinkedList::add_front(Tile* data){
   if (head == nullptr)
   {
      head = data;
   }
   else
   {
  // Make the new node point to the (old) head.
      data->next = head;

  // Make the head pointer point to the new node.
      head = new_node;
   }
    
}
void LinkedList::add_back(Tile* data){
    
}

void LinkedList::remove_front(){
    
}
void LinkedList::remove_back(){
    
}

void LinkedList::remove(int index){
    
}

void LinkedList::clear(){
    
}