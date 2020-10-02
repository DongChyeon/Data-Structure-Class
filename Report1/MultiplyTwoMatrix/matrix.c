#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

// get the current time in milliseconds
long get_currentTime(void)
{
  clock_t start;
  start = clock();
  return((long)((double)start * 1000.0 / (double)CLOCKS_PER_SEC));
}

// create a 2-dimensional array with size rows x cols
int **array(int rows, int cols){
	int **arr = (int **) malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; i++) {
	   arr[i] = (int *) malloc(sizeof(int) * cols);
	}
	return arr;
}

// create a 1-dimensional array with size rows
int *vector(int size){
	int *vec = (int *) malloc(sizeof(int) * size);

	return vec;
}

// Create a Matrix structure
Matrix *make_matrix(int rows, int cols) {
	Matrix *mat = malloc(sizeof(Matrix));
	mat->rows = rows;
	mat->cols = cols;
	mat->val = array(rows, cols);

	return mat;
}

// deallocate a 2-dimensional array with size rows x cols
void freeArray(int **arr, int rows) {
	for (int r=0; r < rows; r++) {
	    freeVector(arr[r]);
	}
	free(arr);
}

// deallocate a 1-dimensional array 
void freeVector(int *vec) {
    free(vec);
}

// deallocate Matrix structure
void freeMatrix(Matrix *mat) {
	freeArray(mat->val, mat->rows);
	free(mat);
}

void multiplyTwoMatrix(Matrix *res, Matrix *a, Matrix *b) {
   float sum;

   for (int r = 0; r < a->rows; r++) {
      for (int c = 0; c < b->cols; c++) {
         sum = 0;
	      for (int k = 0; k < a->cols; k++) {
	         sum += a->val[r][k] * b->val[k][c];
         }
	      res->val[r][c] = sum;
      }
   }
}

// output the contents of a 2-dimensional array with a message msg
void printArray(int **arr, int rows, int cols, char *msg){
	printf("%s\n", msg );
	for (int r = 0; r < rows; r++) {
		for (int c= 0; c < cols; c++) {
		   printf("%d\t", arr[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

// output the contents of a 2-dimensional array with a message msg
void printVector(int *arr, int rows, char *msg){
	printf("%s\n", msg);
	for (int r=0; r<rows; r++) {
	   printf("\t %d", arr[r]);
	}
	printf("\n");
}

// output the contents of Matrix structure with a message msg
void printMatrix(Matrix *mat, char *msg) {
	printArray(mat->val, mat->rows, mat->cols, msg);
}

// return an integer random number between 0 and range-1
int mrand(int range){
    return rand() % range;
}

// fill the contents of a 2-dimensional array with random number
void fill_random_numbers(Matrix *mat, int range, unsigned int seed) {
	for (int r = 0; r < mat->rows; r++) {
		for (int c = 0; c < mat->cols; c++) {
			mat->val[r][c] = mrand(range);
		}
	}
}
