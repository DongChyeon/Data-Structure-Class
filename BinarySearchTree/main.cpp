#include "binarySearchTree.h"

int main() {
    BinarySearchTree tree;
    
    int arr[10] = { 50, 17, 66, 19, 5, 60, 92, 80, 1, 13 };

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        tree.insert(new BinaryNode(arr[i], NULL, NULL));
    }

    cout << "inorder\n";
    tree.inorder(tree.getRoot());
    cout << endl << "preorder\n";
    tree.preorder(tree.getRoot());
    cout << endl << "postorder\n";
    tree.postorder(tree.getRoot());
    cout << endl << "levelorder\n";
    tree.levelorder(tree.getRoot());
    cout << endl;

    return 0;
}