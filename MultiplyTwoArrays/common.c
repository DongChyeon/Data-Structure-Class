#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include"common.h"

long get_runtime(void)
{
  clock_t start;
  start = clock();
  return((long)((double)start*1000000.0/(double)CLOCKS_PER_SEC));
}

// create a 2-dimensional array with size rows x cols
int **array(int rows, int cols){
	int **arr;
	int i;

	arr = (int **) malloc( sizeof( int *) * rows );
	for( i=0; i<rows; i++)
	   arr[i] = (int *) malloc( sizeof( int ) * cols );

	return arr;
}

// create a 1-dimensional array with size rows
int *vector(int rows){
	int *vec;

	vec = (int *) malloc( sizeof( int ) * rows );

	return vec;
}

// deallocate a 2-dimensional array with size rows x cols
void freeArray(int **arr, int rows ){
	int r, c;
	for( r=0; r<rows; r++)
	    freeVector( arr[r] );

	free(arr);
}

// deallocate a 1-dimensional array 
void freeVector(int *vec ){
    free( vec );
}

// output the contents of a 2-dimensional array with a message msg
void printArray(int **arr, int rows, int cols, char *msg){
	int r, c;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
		for(c=0; c<cols; c++)
		   printf("\t %d", arr[r][c]);
		printf("\n");
	}
}

// output the contents of a 2-dimensional array with a message msg
void printVector(int *arr, int rows, char *msg){
	int r;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
	   printf("\t %d", arr[r]);
	}
	printf("\n");
}

// return an integer random number between 0 and range-1
int mrand(int range){
    return rand() % range;
}
