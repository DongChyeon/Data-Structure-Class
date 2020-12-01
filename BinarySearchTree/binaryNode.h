#include <iostream>
using namespace std;

class BinaryNode {
private:
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int val, BinaryNode* left, BinaryNode* right);
    void setData(int val);
    void setLeft(BinaryNode* left);
    void setRight(BinaryNode* right);
    int getData();
    BinaryNode* getLeft();
    BinaryNode* getRight();
    bool isLeaf();
};