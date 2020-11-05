#include <stdio.h>
#include "doublyLinkedList.h"

int main() {
    LinkedList list = makeList();
    addItem(list, 1);
    addItem(list, 2);
    addItem(list, 3);
    addItem(list, 4);
    printListItems(list);

    deleteItem(list, 3);
    printListItems(list);

    deleteItem(list, 1);
    printListItems(list);
    findItem(list, 2);
    findItem(list, 1);

    makeListEmpty(list);
    printListItems(list);

    deleteList(list);

    return 0;
}