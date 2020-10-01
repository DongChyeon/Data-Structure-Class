#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "common.h"

long get_runtime(void)
{
  clock_t start;
  start = clock();
  return((long)((double)start*1000000.0/(double)CLOCKS_PER_SEC));
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
int *vector(int rows){
	int *vec = (int *) malloc(sizeof(int) * rows);

	return vec;
}

Matrix make_matrix(int rows, int cols) {
	Matrix temp;
	temp.rows = rows;
	temp.cols = cols;
	temp.val = array(rows, cols);

	return temp;
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

void freeMatrix(Matrix mat) {
	freeArray(mat.val, mat.rows);
	mat.rows = 0;
	mat.cols = 0;
}

// output the contents of a 2-dimensional array with a message msg
void printArray(int **arr, int rows, int cols, char *msg){
	printf("%s\n", msg );
	for (int r = 0; r < rows; r++) {
		for (int c= 0; c < cols; c++) {
		   printf("\t %d", arr[r][c]);
		}
		printf("\n");
	}
}

// output the contents of a 2-dimensional array with a message msg
void printVector(int *arr, int rows, char *msg){
	printf("%s\n", msg);
	for (int r=0; r<rows; r++) {
	   printf("\t %d", arr[r]);
	}
	printf("\n");
}

void printMatrix(Matrix mat, char *msg) {
	printArray(mat.val, mat.rows, mat.cols, msg);
}

// return an integer random number between 0 and range-1
int mrand(int range){
    return rand() % range;
}

void fill_random_numbers(Matrix mat, int range) {
	for (int r = 0; r < mat.rows; r++) {
		for (int c = 0; c < mat.cols; c++) {
			mat.val[r][c] = mrand(range);
		}
	}
}
