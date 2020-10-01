#ifndef _COMMON_

#define _COMMON_

typedef struct {
    int **val;
    int rows;
    int cols;
} Matrix;

long get_runtime(void);

int **array(int rows, int cols);
int *vector(int rows);
Matrix make_matrix(int rows, int cols);

void freeArray(int **arr, int rows);
void freeVector(int *vec);
void freeMatrix(Matrix mat);

void printArray(int **arr, int rows, int cols, char *msg);
void printVector(int *arr, int rows, char *msg);
void printMatrix(Matrix mat, char *msg);

int mrand(int range);
void fill_random_numbers(Matrix mat, int range);

#endif
