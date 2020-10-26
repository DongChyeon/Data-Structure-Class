#include <stdio.h>
#include "polynomial.h"

int main() {
    poly_node a, b, c;

    a = makeList();
    b = makeList();

    append(3, 14, a);
    append(2, 8, a);
    append(1, 0, a);
    append(8, 14, b);
    append(3, 10, b);
    append(10, 6, b);

    c = poly_add(a, b);

    printNodes(a);
    printNodes(b);
    printNodes(c);

    return 0;
}