#include <cstdio>

class Node {
protected:
    int id;
    Node* link;
public:
    Node(int i, Node *link);
    ~Node();
    int getId();
    Node* getLink();
    void setLink(Node* link);
};