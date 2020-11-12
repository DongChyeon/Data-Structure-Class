#include <stdio.h>
#include "binaryTree.h"

int main() {
    BinaryTree tree = makeTree();

    BinaryNode f = makeNode(6, NULL, NULL);
    BinaryNode e = makeNode(5, NULL, NULL);
    BinaryNode d = makeNode(4, NULL, NULL);
    BinaryNode c = makeNode(3, f, NULL);
    BinaryNode b = makeNode(2, d, e);
    BinaryNode a = makeNode(1, b, c);

    setRoot(tree, a);

    printInorder(tree);
    printPreorder(tree);
    printPostorder(tree);
    printLevelorder(tree);

    return 0; 
}