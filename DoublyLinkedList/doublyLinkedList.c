#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doublyLinkedList.h"

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
    do {
        printf("%d\t", tnode->value);
        tnode = tnode->rlink;
    } while (tnode != list->head);
    printf("\n");
}

List makeList() {
    List list = (List)malloc(sizeof(struct head_pointer));
    list->head = NULL;

    return list;
}

void addItem(List list, Element elem) {
    list_pointer lnode, rnode;
    list_pointer inode = (list_pointer)malloc(sizeof(struct list_node));
    if (inode == NULL) {
        printf("::Unable to allocate more memory!!!\n");
    }
    if (isEmpty(list)) {
        list->head = inode;
        inode->value = elem;
        inode->llink = inode;
        inode->rlink = inode;
    } else {
        rnode = list->head;
        lnode = rnode->llink;

        inode->value = elem;
        inode->llink = lnode;
        inode->rlink = rnode;

        lnode->rlink = inode;
        rnode->llink = inode;
    }
}

Node findItem(List list, Element elem) {
    if (isEmpty(list)) {
        printf("%d does not exist.\n", elem);
        return NULL;
    }

    Node tnode = list->head;
    do {
        if (tnode->value == elem) {
            printf("%d is in List.\n", elem);
            return tnode;
        }
        tnode = tnode->rlink;
    } while (tnode != list->head);
    printf("%d does not exist.\n", elem);

    return NULL;
}

void deleteItem(List list, Element elem) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    Node dnode = list->head;
    do {
        if (dnode->value == elem) {
            if (dnode == list->head) {
                list->head = dnode->rlink;
            }
            dnode->llink->rlink = dnode->rlink;
            dnode->rlink->llink = dnode->llink;
            free(dnode);
            break;
        }
        dnode = dnode->rlink;
    } while (dnode != list->head);
}

void makeListEmpty(List list) {
    Node dnode = list->head;
    Node tnode = dnode->rlink;
    Node enode = dnode->llink;

    while (dnode != enode) {
        free(dnode);
        dnode = tnode;
        tnode = dnode->rlink;
    }
    list->head = NULL;
}

void deleteList(List list) {
    makeListEmpty(list);
    free(list);
}