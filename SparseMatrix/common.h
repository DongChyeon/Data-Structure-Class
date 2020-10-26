#ifndef _COMMON_
#define _COMMON_

#define MAX_TERMS 101

typedef struct
{
    int col;
    int row;
    int value;
} SPARSE_MATRIX;

int get_value(int r, int c, SPARSE_MATRIX *s);
int **array(int rows, int cols);
void freeArray(int **arr, int rows);
void freeVector( int *vec);
void printArray(int **arr, int rows, int cols, char *msg);

#endif