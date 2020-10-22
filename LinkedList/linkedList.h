#include <stdbool.h>

typedef int Element;
typedef struct list_node *list_pointer;
typedef list_pointer List;
typedef list_pointer Node;
typedef struct list_node {
    Element value;
    list_pointer link;
} list_node;

bool isEmpty(List list);
void writeListItem(List list);
List makeFirstItem(Element elem);
List addItem(List list, Element elem);
Node findItem(List list, Element elem);
List deleteFirstItem(List list);
List deleteItem(List list, Element elem);
List makeListEmpty(List list);
