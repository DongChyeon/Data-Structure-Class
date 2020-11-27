#include "node.h"

Node::Node(int id, Node *link) {
    this->id = id;
    this->link = link;
}

Node::~Node() {
    if (link != NULL)
        delete link;
}

int Node::getId() {
    return id;
}

Node* Node::getLink() {
    return link;
}

void Node::setLink(Node* link) {
    link = link;
}