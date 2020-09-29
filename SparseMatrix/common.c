#include "common.h"

int get_value(int r, int c, SPARSE_MATRIX *s) {
    int k;
    
    if (r < 0 || r >= s[0].row || c < 0 || c >= s[0].col) {
        printf("r or c index out of range\n");
        exit(-1);
    }

    for (k = 1; k < s[0].value; k++) {
        if (s[k].row == r && s[k].col == c) {
            return s[k].value;
        }
    }
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
void freeVector(int *vec) {
	free(vec);
}

// output the contents of a 2-dimensional array with a message msg
void printArray( int **arr, int rows, int cols, char *msg){
	int r, c;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
		for(c=0; c<cols; c++)
		   printf("\t %d", arr[r][c]);
		printf("\n");
	}
}