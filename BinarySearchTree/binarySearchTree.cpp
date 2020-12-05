#include "binarySearchTree.h"

BinarySearchTree::BinarySearchTree() { }
void BinarySearchTree::setRoot(BinaryNode* node) { root = node; }
BinaryNode* BinarySearchTree::getRoot() { return root; }
bool BinarySearchTree::isEmpty() { return root == NULL; }

void BinarySearchTree::inorder(BinaryNode* node, bool isAsec) 
{   
    if (isAsec) {
        if (node != NULL) {
            inorder(node->getLeft(), true);
            printf("[%d] ", node->getData());
            inorder(node->getRight(), true);
        }
    } else {
        if (node != NULL) {
            inorder(node->getRight(), false);
            printf("[%d] ", node->getData());
            inorder(node->getLeft(), false);
        }
    }
}

void BinarySearchTree::preorder(BinaryNode* node) {
    if (node != NULL) {
        printf("[%d] ", node->getData());
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}

void BinarySearchTree::postorder(BinaryNode* node) {
    if (node != NULL) {
        postorder(node->getLeft());
        postorder(node->getRight());
        printf("[%d] ", node->getData());
    }
}

void BinarySearchTree::levelorder(BinaryNode* node) {
    queue<BinaryNode *> queue;
    queue.push(node);
    while (!queue.empty()) {
        BinaryNode* temp = queue.front();
        queue.pop();
        if (temp != NULL) {
            printf("[%d] ", temp->getData());
            queue.push(temp->getLeft());
            queue.push(temp->getRight());
        }
    }
}


BinaryNode* BinarySearchTree::search(BinaryNode* node, int key) {
    while (node != NULL) {
        if (key == node->getData())
            return node;
        else if (key < node->getData())
            node = node->getLeft();
        else
            node = node->getRight();
    }

    return NULL;
}

void BinarySearchTree::insert(BinaryNode* node) {
    if (node == NULL) return;
    if (isEmpty()) root = node;
    else insertRecur(root, node);
}

void BinarySearchTree::insertRecur(BinaryNode* root, BinaryNode* node) {
    if (node->getData() == root->getData()) {
        return;
    } else if (node->getData() < root->getData()) {
        if (root->getLeft() == NULL)
            root->setLeft(node);
        else
            insertRecur(root->getLeft(), node);
    } else {
        if (root->getRight() == NULL)
            root->setRight(node);
        else
            insertRecur(root->getRight(), node);
    }
}