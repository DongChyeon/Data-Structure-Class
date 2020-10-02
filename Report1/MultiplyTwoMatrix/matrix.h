#ifndef _COMMON_

#define _COMMON_

typedef struct {
    int **val;
    int rows;
    int cols;
} Matrix;

long get_currentTime(void);

int **array(int rows, int cols);
int *vector(int size);
Matrix *make_matrix(int rows, int cols);

void freeArray(int **arr, int rows);
void freeVector(int *vec);
void freeMatrix(Matrix *mat);

void multiplyTwoMatrix(Matrix *res, Matrix *a, Matrix *b);

void printArray(int **arr, int rows, int cols, char *msg);
void printVector(int *arr, int rows, char *msg);
void printMatrix(Matrix *mat, char *msg);

int mrand(int range);
void fill_random_numbers(Matrix *mat, int range, unsigned int seed);

#endif
