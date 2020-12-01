#include "binaryNode.h"

BinaryNode::BinaryNode(int val, BinaryNode* left, BinaryNode* right) {
    data = val;
    this->left = left;
    this->right = right;
}

void BinaryNode::setData(int val) { data = val; }
void BinaryNode::setLeft(BinaryNode* left) { this->left = left; }
void BinaryNode::setRight(BinaryNode* right) { this->right = right; }
int BinaryNode::getData() { return data; }
BinaryNode* BinaryNode::getLeft() { return left; }
BinaryNode* BinaryNode::getRight() { return right;}
bool BinaryNode::isLeaf() { return left == NULL && right == NULL; }