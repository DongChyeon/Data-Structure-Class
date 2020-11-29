#include "node.h"

Node::Node(int id, Node *link, int weight) {
    this->id = id;
    this->link = link;
    this->weight = weight;
}

Node::~Node() {
    if (link != NULL)
        delete link;
}

int Node::getId() {
    return id;
}

int Node::getWeight() {
    return weight;
}

Node* Node::getLink() {
    return link;
}

void Node::setLink(Node* link) {
    link = link;
}