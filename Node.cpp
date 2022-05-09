
#include "Node.h"

Node::Node() {
    tile = nullptr;
    next = nullptr;
}

Node::Node(Tile* tile, Node* next) {
    this->tile = tile;
    this->next = next;
}

Node::Node(Node& other)
{
    node = new LinkedList(*other.node);
}

Node::~Node()
{
    tile = nullptr;
    next = nullptr;
}
