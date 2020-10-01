#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void multiplyTwoNodes( int **res, int **a, int **b, int m, int n, int q){
   int r, c, k;
   int sum;

   for(r=0; r<m; r++)
      for(c=0; c<q; c++){
          sum = 0;
	  for(k=0; k<n; k++)
	      sum += a[r][k] + b[k][c];
	  res[r][c] = sum;
      }
}


int main(){
    int m = 10, n= 5, q = 6;
    int r, c;
    int **a, **b, **res;

    long start, end;

    a = array( m, n);
    b = array( n, q);
    res = array( m, q);

    /* assign some values to the arrays */
    for(r=0; r<m; r++)
        for(c=0; c<n; c++)
           a[r][c] = mrand( 10 );

    for(r=0; r<n; r++)
        for(c=0; c<q; c++)
           b[r][c] = mrand( 5 );

    start = get_runtime();
    /* multiply a[][] and b[][] */
    multiplyTwoNodes( res, a, b, m, n, q);
    end = get_runtime();
    printf("�ɸ� �ð� : %ld ����ũ�� ��\n", end - start);

    printNode( a, m, n, "A");
    printNode( b, n, q, "B");
    printNode( res, m, q, "C");

    freeNode(a, m);
    freeNode(b, n);
    freeNode(res, m);

    return 0;
}
