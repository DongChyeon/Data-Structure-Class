#include "node.h"

Node::Node(int i, Node *l) {
    id = i;
    link = l;
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