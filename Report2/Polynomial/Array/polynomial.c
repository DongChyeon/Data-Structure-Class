#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polynomial.h"

Poly makePoly(int degree) {
    Poly poly;
    
    poly = (Poly)malloc(sizeof(struct poly));
    if (poly == NULL) {
        printf("The memory is full\n");
        exit(1);
    }
    poly->degree = degree;
    poly->coef = (int *)malloc(sizeof(int) * (degree + 1));
    for (int i = 0; i < poly->degree + 1; i++) {
        poly->coef[i] = 0;
    }

    return poly;
}

void printPoly(Poly poly) {
    int isFirstTerm = true;

    for (int i = poly->degree; i > -1; i--) {
        if (i == 0) {
            if (poly->coef[i] < 0)
                printf(" - %d", -poly->coef[i]);
            else if (poly->coef[i] > 0)
                printf(" + %d", poly->coef[i]);
        } else {
            if (isFirstTerm) {
                if (poly->coef[i] < 0) {
                    printf("-%dx^%d", -poly->coef[i], i);
                    isFirstTerm = false;
                } else if (poly->coef[i] > 0) {
                    printf("%dx^%d", poly->coef[i], i);
                    isFirstTerm = false;
                }
            } else {
                if (poly->coef[i] < 0)
                    printf(" - %dx^%d", -poly->coef[i], i);
                else if (poly->coef[i] > 0)
                    printf(" + %dx^%d", poly->coef[i], i);
            }
        }
    }
    printf("\n");
}

void append(int coef, int expon, Poly poly) {
    poly->coef[expon] = coef;
}

void erase(Poly poly) {
    free(poly);
}

Poly poly_add(Poly a, Poly b) {
    int degree = 0;
    if (a->degree > b->degree)
        degree = a->degree;
    else
        degree = b->degree;
    Poly poly = makePoly(degree);

    for (int i = degree; i > -1; i--) {
        if (a->coef[i] != 0 && b->coef[i] != 0) {
            poly->coef[i] = a->coef[i] + b->coef[i];
        }
        else {
            if (a->coef[i] != 0)
                poly->coef[i] = a->coef[i];
            if (b->coef[i] != 0)
                poly->coef[i] = b->coef[i];
        }
    }

    return poly;
}

Poly poly_sub(Poly a, Poly b) {
    int degree = 0;
    if (a->degree > b->degree)
        degree = a->degree;
    else
        degree = b->degree;
    Poly poly = makePoly(degree);

    for (int i = degree; i > -1; i--) {
        if (a->coef[i] != 0 && b->coef[i] != 0) {
            poly->coef[i] = a->coef[i] - b->coef[i];
        }
        else {
            if (a->coef[i] != 0)
                poly->coef[i] = a->coef[i];
            if (b->coef[i] != 0)
                poly->coef[i] = b->coef[i];
        }
    }

    return poly;
}

int COMPARE(int a, int b) {
    if (a < b) return -1;
    else if (a > b) return 1;
    else return 0;
}

Poly makeRandomPoly(int degree, int coef, int count, unsigned int seed) {
    Poly poly = makePoly(degree);

    int cnt = 0;
    int randomCoef, randomExpon;
    srand(seed);
    while (cnt < count) {
        do {
            randomCoef = rand() % (coef * 2) - coef;
        } while (randomCoef == 0);
        randomExpon = (rand() % degree) + 1;
        if (poly->coef[randomExpon] == 0) {
            cnt++;
            append(randomCoef, randomExpon, poly);
        }
    }

    return poly;
}