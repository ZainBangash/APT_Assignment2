#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   for(int i = 0; i < other.size(); ++i){
        Tile* tile = new Tile(*other.get(i));
        add_back(tile);
    }
}

LinkedList::~LinkedList() {
   clear();
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
    if(head != nullptr){
        Node* current = head;
        //pre should point to node before current;
        Node* prev = nullptr;

        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }

        if(prev == nullptr){
            head = nullptr;
        }else{
            prev->next = nullptr;
        }

        delete current->tile;
        delete current;
    }
 
}

void LinkedList::remove(int index){
    if(index >= 0 && index < size()){
        if(head != nullptr){
            int counter = 0;
            Node* current = head;
            //pre should point to node before current;
            Node* prev = nullptr;

            while(counter != index){
                ++counter;
                prev = current;
                current = current->next;
            }

            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }

            delete current->tile;
            delete current;
        }
    }

}

void LinkedList::clear(){
    while(head != nullptr){
        remove_front();
    }
}