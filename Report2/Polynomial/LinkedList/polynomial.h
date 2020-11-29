#ifndef _POLYNOMIAL_

#define _POLYNOMIAL_

typedef struct term_node* poly_ptr;
typedef poly_ptr poly_node;
typedef struct term_node {
    int coef;
    int expon;
    poly_ptr link;
} term_node;

poly_node makePoly();
void printPoly(poly_node node);
void append(int coef, int expon, poly_node ptr);
void erase(poly_node ptr);
// poly_node poly_multiply(poly_node a, poly_node b);
poly_node poly_add(poly_node a, poly_node b);
poly_node poly_sub(poly_node a, poly_node b);
int COMPARE(int a, int b);
poly_node makeRandomPoly(int coef, int count, unsigned int seed);

#endif