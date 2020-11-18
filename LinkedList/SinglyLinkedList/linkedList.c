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

void printListItems(List list) {
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

List makeList() {
    List list = (List)malloc(sizeof(struct head_pointer));
    list->head = NULL;

    return list;
}

void addItem(List list, Element elem) {
    list_pointer ptrNode = (list_pointer)malloc(sizeof(struct list_node));
    if (ptrNode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    ptrNode->value = elem;
    if (isEmpty(list)) {
        list->head = ptrNode;
        ptrNode->link = NULL;
    } else {
        ptrNode->link = list->head;
        list->head = ptrNode;
    }
}

Node findItem(List list, Element elem) {
    if (isEmpty(list)) {
        printf("%d does not exist.\n", elem);
        return NULL;
    }

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

void deleteItem(List list, Element elem) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    Node anode = list->head;
    Node dnode = anode->link;
    if (anode->value == elem) {
        list->head = dnode;
        free(anode);
    }
    
    while (dnode != NULL) {
        if (dnode->value == elem) {
            anode->link = dnode->link;
            free(dnode);
            break;
        }
        anode = dnode;
        dnode = anode->link;
    }
}

void makeListEmpty(List list) {
    Node anode = list->head;
    Node bnode;
    while (anode != NULL) {
        bnode = anode->link;
        free(anode);
        anode = bnode;
    }
    list->head = NULL;
}

void deleteList(List list) {
    makeListEmpty(list);
    free(list);
}