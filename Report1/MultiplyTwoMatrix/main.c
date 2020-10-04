#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main() {
   unsigned int seed = time(NULL);
   long start, end;
   
   int m = 225, n = 200, p = 275;
   Matrix *a, *b, *res;

   a = make_matrix(m, n);
   b = make_matrix(n, p);
   res = make_matrix(m, p);

   fill_random_numbers(a, 5, seed);
   fill_random_numbers(b, 5, seed);

   start = get_currentTime();
   multiplyTwoMatrix(res, a, b);
   end = get_currentTime();

   //printMatrix(a, "A");
   //printMatrix(b, "B");
   //printMatrix(res, "res");

   printf("Execution time : %ld msec\n", end - start);

   freeMatrix(a);
   freeMatrix(b);
   freeMatrix(res);

   return 0;
}
