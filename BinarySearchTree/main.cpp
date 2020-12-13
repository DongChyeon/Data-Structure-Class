#include "binarySearchTree.h"

int main() {
    BinarySearchTree tree;
    
    int arr[13] = { 30, 10, 25, 15, 80, 35, 1, 45, 89, 90, 11, 6, 66 };

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        tree.insert(new BinaryNode(arr[i], NULL, NULL));
    }

    cout << "inorder(ASEC)\n";
    tree.inorder(tree.getRoot(), true);
    cout << "\ninorder(DESC)\n";
    tree.inorder(tree.getRoot(), false);
    cout << "\npreorder\n";
    tree.preorder(tree.getRoot());
    cout << "\npostorder\n";
    tree.postorder(tree.getRoot());
    cout << "\nlevelorder\n";
    tree.levelorder(tree.getRoot());
    tree.remove(60);
    cout << "\nlevelorder\n";
    tree.levelorder(tree.getRoot());
    cout << endl;

    return 0;
}