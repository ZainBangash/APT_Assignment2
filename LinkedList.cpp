#include "LinkedList.h"


LinkedList::LinkedList() {
    head = nullptr;
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
    // fill new node at head
    this->head = new Node(tile, this->head);

}


void LinkedList::add_back(Tile* tile){
    if(head == nullptr) {
        head = new Node(tile, nullptr);
    } else {

    //traverse to the last node
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

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
    if (head != nullptr){
        // if there is only one node, delete it
        if (head->next == nullptr) {
            delete head;
        } else {

            // Find the second last node
            Node* second_last = head;
            while (second_last->next->next != nullptr) {
                second_last = second_last->next;
            }

            // Delete last node
            delete second_last->next;
            second_last->next = nullptr;
        }

    } else {
        cout <<"The list is empty" << endl;
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
                // runs when the node to remove is the first node
                head = head->next;
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
