#include <stdio.h>
#include "polynomial.h"

int main() {
    poly_node a, b, c;

    a = makePoly();
    b = makePoly();

    append(3, 14, a);
    append(4, 10, a);
    append(2, 8, a);
    append(3, 6, a);
    append(1, 0, a);    
    
    append(8, 14, b);
    append(3, 10, b);
    append(10, 6, b);
    append(2, 3, b);
    append(5, 0, b);

    c = poly_add(a, b);

    printPoly(a);
    printPoly(b);
    printPoly(c);

    c = poly_sub(a,b);

    printPoly(a);
    printPoly(b);
    printPoly(c);

    return 0;
}