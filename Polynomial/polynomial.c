#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

poly_node makeList() {
    poly_node node;

    node = (poly_node)malloc(sizeof(struct term_node));
    if (node == NULL) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    node->link = NULL;

    return node;
}

void printNodes(poly_node node) {
    poly_node temp = node->link;

    while (temp) {
        if (temp->expon == 0) 
            printf("%d ", temp->coef);
        else 
            printf("%d^%d ", temp->coef, temp->expon);
        temp = temp->link;
    }
    printf("\n");
}

void append(int coef, int expon, poly_node ptr) {
    poly_node temp;
    temp = (poly_node)malloc(sizeof(struct term_node));
    if (temp == NULL) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;

    poly_node rear = ptr;
    while (1) {
        if (rear->link == NULL) break;
        rear = rear->link;
    }
    rear->link = temp;
}

void erase(poly_node ptr) {
    poly_node temp;
    while (ptr) {
        temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
}

poly_node poly_add(poly_node a, poly_node b) {
    poly_node front;
    int sum;
    front = (poly_node)malloc(sizeof(struct term_node));
    if (front == NULL) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    front->link = NULL;

    a = a->link;
    b = b->link;
    while (a && b) {
        switch (COMPARE(a->expon, b->expon)) {
        case -1:
            append(b->coef, b->expon, front);
            b = b->link;
            break;
        case 0:
            sum = a->coef + b->coef;
            if (sum) append(sum, a->expon, front);
            a = a->link; b = b->link;
            break;
        case 1:
            append(a->coef, a->expon, front);
            a = a->link;
            break;
        }
    }
    for (; a; a = a->link) append(a->coef, a->expon, front);
    for (; b; b = b->link) append(b->coef, b->expon, front);

    return front;
}

int COMPARE(int a, int b) {
    if (a < b) return -1;
    else if (a > b) return 1;
    else return 0;
}