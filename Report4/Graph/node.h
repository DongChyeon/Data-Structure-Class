#include <iostream>
using namespace std;

class Node {
private:
    int id;
    Node* link;
    int weight;
public:
    Node(int id, Node *link, int weight);
    ~Node();
    int getId();
    int getWeight();
    Node* getLink();
    void setLink(Node* link);
};