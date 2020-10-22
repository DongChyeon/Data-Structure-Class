#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

bool isEmpty(List list) {
    if (list->link == NULL) 
        return true;
    else 
        return false;
}

void writeListItem(List list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    list_pointer tnode = list->link;
    while (tnode != NULL) {
        printf("%d\t", tnode->value);
        tnode = tnode->link;
    }
    printf("\n");
}

List makeFirstItem(Element elem) {
    List list = (list_pointer) malloc(sizeof(struct list_node));
    List fItem = (list_pointer) malloc(sizeof(struct list_node));
    list->link = fItem;
    fItem->value = elem;
    fItem->link = NULL;

    return list;
}

List addItem(List list, Element elem) {
    list_pointer ptrNode = (list_pointer) malloc(sizeof(struct list_node));
    if (ptrNode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    ptrNode->value = elem;
    ptrNode->link = list->link;
    list->link = ptrNode;

    return list;
}

Node findItem(List list, Element elem) {
    Node tnode = list;
    while (tnode != NULL) {
        printf("%d is in List.\n", elem);
        return tnode;
    }
    printf("%d does not exist.\n", elem);

    return NULL;
}

List deleteFirstItem(List list) {
    Node anode = list->link;
    if (anode == NULL) {
        printf("list is empty.\n");
    } else {
        list->link = anode->link;
        free(anode);
    }

    return list;
}

List deleteItem(List list, Element elem) {
    Node anode = list;
    Node dnode = anode->link;
    while (dnode != NULL) {
        if (dnode->value == elem) {
            anode->link = dnode->link;
            free(dnode);
            break;
        }
        anode = dnode;
        dnode = anode->link;
    }
    
    return list;
}

List makeListEmpty(List list) {
    Node anode = list->link;
    Node bnode;
    while (anode != NULL) {
        bnode = anode->link;
        free(anode);
        anode = bnode;
    }
    list->link = NULL;

    return list;
}