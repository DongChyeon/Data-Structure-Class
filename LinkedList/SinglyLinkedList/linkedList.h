#include <stdbool.h>

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

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
void printListItems(List list);
List makeList();
void addItem(List list, Element elem);
Node findItem(List list, Element elem);
void deleteItem(List list, Element elem);
void makeListEmpty(List list);
void deleteList(List list);

#endif