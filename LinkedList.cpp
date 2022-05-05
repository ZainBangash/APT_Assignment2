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
      next = head;

  // Make the head pointer point to the new node.
      head = data;
   }
    
}
void LinkedList::add_back(Tile* data){
   if(head == nullptr) {
    head = data;
  } else {
    
    //5. Else, traverse to the last node
    Node* temp = head;
    while(temp->next != nullptr)
      temp = temp->next;
    
    //6. Change the next of last node to new node
    temp->next = data;
  }
    
}

void LinkedList::remove_front(){
   if (head == nullptr)
        {
            cout << "The list is empty";
        }

        // Check to see if the list has more than one item.
        // If it only has one node erase it.
        if (head->next == nullptr)
        {
            delete head;
        }
        else
        {
            Node* next = head->next;
            delete head;
            head = next;
            head->prev = nullptr;
        }
    
}
void LinkedList::remove_back(){
    if (head == nullptr){
       std::cout <<"The list is empty" << std::endl
    }
 
    if (head->next == nullptr) {
        delete head;
    }
 
    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;
 
    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = nullptr;
 
}

void LinkedList::remove(int index){
    

}

void LinkedList::clear(){
    
}