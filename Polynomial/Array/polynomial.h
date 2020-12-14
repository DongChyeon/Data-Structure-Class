#ifndef _POLYNOMIAL_

#define _POLYNOMIAL_

typedef struct poly* Poly;
typedef struct poly {
    int degree;
    int *coef;
} poly;

Poly makePoly(int degree);
void printPoly(Poly poly);
void append(int coef, int expon, Poly poly);
void erase(Poly poly);
Poly poly_add(Poly a, Poly b);
Poly poly_sub(Poly a, Poly b);
int COMPARE(int a, int b);
Poly makeRandomPoly(int degree, int coef, int count, unsigned int seed);

#endif