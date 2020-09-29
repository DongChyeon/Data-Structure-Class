#include <stdio.h>
#include "common.h"

void multiplyTwoSparses(int **res, SPARSE_MATRIX *A, SPARSE_MATRIX *B) {
    float csum;
    int r, c, k;

    for (r = 0; r < A[0].row; r++) {
        for (c = 0; c < B[0].col; c++) {
            csum = 0;
            for (k = 0; k < A[0].col; k++) {
                csum += get_value(r, k, A) * get_value(k, c, B);
            }
            res[r][c] = csum;
        }
    }
}

int main() {
    int **res;

    SPARSE_MATRIX A[4];
    SPARSE_MATRIX B[5]; 

    // 희소 행렬 A
    A[0].row = 3;
    A[0].col = 4;
    A[0].value = 3;

    A[1].row = 0;
    A[1].col = 2;
    A[1].value = 3;

    A[2].row = 1;
    A[2].col = 1;
    A[2].value = 1;

    A[3].row = 2;
    A[3].col = 2;
    A[3].value = 6;

    // 희소 행렬 B
    B[0].row = 4;
    B[0].col = 5;
    B[0].value = 4;

    B[1].row = 0;
    B[1].col = 2;
    B[1].value = 3;

    B[2].row = 1;
    B[2].col = 1;
    B[2].value = 4;

    B[3].row = 3;
    B[3].col = 3;
    B[3].value = 5;

    B[4].row = 2;
    B[4].col = 4;
    B[4].value = 7;

    // 결과를 저장할 행렬
    res = array(A[0].row, B[0].col);

    multiplyTwoSparses(res, A, B);

    printArray(res, A[0].row, B[0].col, "Result");

    return 0;
}