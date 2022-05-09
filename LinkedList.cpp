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

void LinkedList::add_front(Tile* tile){
    // fill new node
	Node* node = new Node(tile, head);

    // set it to the first node
    head = node;

}
void LinkedList::add_back(Tile* tile){
   if(head == nullptr) {
    head = new Node(tile, nullptr);
  } else {

    //traverse to the last node
    Node* temp = head;
    while(temp->next != nullptr)
      temp = temp->next;

    //Change the next of last node to new node
    temp->next = new Node(tile, nullptr);
  }

}

void LinkedList::remove_front(){
   if (head != nullptr) {
        // Check to see if the list has more than one item.
        // If it only has one node erase it.
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* newHead = head->next;
            delete head;
            head = newHead;
        }

    } else {
        cout << "The list is empty" << endl;
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
            Node* toRemove = head;
            //prev should point to node before current;
            Node* prev = nullptr;

            // count until we find node at index
            while(counter != index){
                ++counter;
                prev = toRemove;
                toRemove = toRemove->next;
            }

            if(prev == nullptr){
                // if there is only one node, remove it
                head = nullptr;
            }else{
                // make the list skip over the removed node
                prev->next = toRemove->next;
            }

            delete toRemove;

        }
    } else {
        cout << "invalid index: " << index << endl;
    }

}

void LinkedList::clear(){
    while(head != nullptr){
        remove_front();
    }
}
