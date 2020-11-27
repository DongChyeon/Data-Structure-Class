#include <cstdio>

class Node {
protected:
    int id;
    Node* link;
public:
    Node(int id, Node *link);
    ~Node();
    int getId();
    Node* getLink();
    void setLink(Node* link);
};