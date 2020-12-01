#include <stdio.h>
#include <time.h>
#include "polynomial.h"

long getCurrentTime(void)
{
  clock_t start;
  start = clock();
  return ((long)((double)start * 1000000.0 / (double)CLOCKS_PER_SEC));
}

int main() {
    poly_node a, b, c;
    int seed = time(NULL);
    long start, end;

    for (int i = 0; i < 5; i++) {
        a = makeRandomPoly(50, 10000, seed + i);
        b = makeRandomPoly(50, 10000, seed + (i + 1) * 101);

        start = getCurrentTime();
        c = poly_add(a, b);
        end = getCurrentTime();

        //printPoly(a);
        //printPoly(b);
        //printPoly(c);
        printf("Elapsed time : %ld us\n\n", end - start);

        start = getCurrentTime();
        c = poly_sub(a,b);
        end = getCurrentTime();

        //printPoly(a);
        //printPoly(b);
        //printPoly(c);
        printf("Elapsed time : %ld us\n\n", end - start);
    }
    erase(a);
    erase(b);
    erase(c);

    return 0;
}