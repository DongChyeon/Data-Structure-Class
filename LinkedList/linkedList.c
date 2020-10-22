#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

bool isEmpty(List list) {
    if (list->head == NULL)
        return true;
    else
        return false;
}

void writeListItem(List list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    list_pointer tnode = list->head;
    while (tnode != NULL) {
        printf("%d\t", tnode->value);
        tnode = tnode->link;
    }
    printf("\n");
}

List makeFirstItem(Element elem) {
    List list = (List)malloc(sizeof(struct head_pointer));
    Node fItem = (list_pointer)malloc(sizeof(struct list_node));
    list->head = fItem;
    fItem->value = elem;
    fItem->link = NULL;

    return list;
}

List addItem(List list, Element elem) {
    list_pointer ptrNode = (list_pointer)malloc(sizeof(struct list_node));
    if (ptrNode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    ptrNode->value = elem;
    ptrNode->link = list->head;
    list->head = ptrNode;

    return list;
}

Node findItem(List list, Element elem) {
    Node tnode = list->head;
    while (tnode != NULL) {
        if (tnode->value == elem) {
            printf("%d is in List.\n", elem);
            return tnode;
        }
        tnode = tnode->link;
    }
    printf("%d does not exist.\n", elem);

    return NULL;
}

List deleteFirstItem(List list) {
    Node anode = list->head;
    if (anode == NULL) {
        printf("list is empty.\n");
    }
    else {
        list->head = anode->link;
        free(anode);
    }

    return list;
}

List deleteItem(List list, Element elem) {
    Node anode = list->head;
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
    Node anode = list->head;
    Node bnode;
    while (anode != NULL) {
        bnode = anode->link;
        free(anode);
        anode = bnode;
    }
    list->head = NULL;

    return list;
}

void deleteList(List list) {
    makeListEmpty(list);
    free(list);
}