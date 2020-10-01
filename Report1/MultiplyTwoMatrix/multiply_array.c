#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void multiplyTwoMatrix(Matrix res, Matrix a, Matrix b) {
   float sum;

   for (int r = 0; r < a.rows; r++) {
      for (int c = 0; c < b.cols; c++) {
         sum = 0;
	      for (int k = 0; k < a.cols; k++) {
	         sum += a.val[r][k] * b.val[k][c];
         }
	      res.val[r][c] = sum;
      }
   }
}

int main() {
   int m = 3, n = 2, q = 4;
   int r, c;
   Matrix a, b, res;

   long start, end;

   a = make_matrix(m, n);
   b = make_matrix(n, q);
   res = make_matrix(m, q);

   /* assign some values to the arrays */
   fill_random_numbers(a, 5);
   fill_random_numbers(b, 5);

   start = get_runtime();
   /* multiply a[][] and b[][] */
   multiplyTwoMatrix(res, a, b);
   end = get_runtime();

   printMatrix(a, "A");
   printMatrix(b, "B");
   printMatrix(res, "res");

   printf("Duration of time : %ld micro seconds\n", end - start);

   freeMatrix(a);
   freeMatrix(b);
   freeMatrix(res);

   return 0;
}
