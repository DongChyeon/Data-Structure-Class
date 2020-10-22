#include <stdbool.h>

typedef int Element;
typedef struct list_node* list_pointer;
typedef struct head_pointer* LinkedList;
typedef LinkedList List;
typedef list_pointer Node;
typedef struct list_node {
    Element value;
    list_pointer link;
} list_node;
typedef struct head_pointer {
    list_pointer head;
} head_pointer;

bool isEmpty(List list);
void writeListItem(List list);
List makeFirstItem(Element elem);
List addItem(List list, Element elem);
Node findItem(List list, Element elem);
List deleteFirstItem(List list);
List deleteItem(List list, Element elem);
List makeListEmpty(List list);
void deleteList(List list);

