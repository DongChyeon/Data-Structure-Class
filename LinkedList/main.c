#include <stdio.h>
#include "linkedList.h"

int main() {
    LinkedList list = makeFirstItem(1);
    list = addItem(list, 2);
    list = addItem(list, 3);
    writeListItem(list);

    deleteFirstItem(list);
    writeListItem(list);

    deleteItem(list, 1);
    writeListItem(list);

    makeListEmpty(list);
    writeListItem(list);

    deleteList(list);

    return 0;
}