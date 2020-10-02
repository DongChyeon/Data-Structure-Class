#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

// get the current time in milliseconds
long get_currentTime(void)
{
    clock_t start;
    start = clock();
    return((long)((double)start * 1000.0 / (double)CLOCKS_PER_SEC));
}

// create a 1-dimensional array with size
int* vector(int size) {
    int* vec = (int*)malloc(sizeof(int) * size);

    return vec;
}

// create a Array structure
Array *make_array(int size) {
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->size = size;
    arr->val = vector(size);

    return arr;
}

// deallocate a 1-dimensional array
void freeVector(int* vec) {
    free(vec);
}

// deallocate Array structrue
void freeArray(Array* arr) {
    freeVector(arr->val);
    free(arr);
}

// swap two elements
void swap(int* val1, int* val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void selection_sort(Array* arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        int least = i;
        for (int j = i + 1; j < arr->size; j++) {
            if (arr->val[j] < arr->val[least]) {
                least = j;
            }
        }
        swap(&arr->val[i], &arr->val[least]);
    }
}

void insertion_sort(Array* arr) {
    for (int i = 1; i < arr->size; i++) {
        int key = arr->val[i];
        int j = i - 1;
        while (j >= 0 && arr->val[j] > key) {
            arr->val[j + 1] = arr->val[j];
            j--;
        }
        arr->val[j + 1] = key;
    }
}

// improved bubble sort
void bubble_sort(Array* arr) {
    int isSorted = 0;

    for (int i = arr->size - 1; i > 0 && !isSorted; i--) {
        isSorted = 1;
        for (int j = 0; j < i; j++) {
            if (arr->val[j] > arr->val[j + 1]) {
                swap(&arr->val[j], &arr->val[j + 1]);
                isSorted = 0;
            }
        }
    }
}

// output the contents of 1-dimensional array with a mssage msg
void print_array(Array* arr, char* msg) {
    printf("%s\n", msg);
    for (int i = 0; i < arr->size; i++) {
        printf("%d\t", arr->val[i]);
        if ((i + 1) != 1 && (i + 1) % 10 == 0) {
            printf("\n");
        }   // Output ten elements per a row
    }
    printf("\n\n");
}

// return an integer random number between 0 and range-1
int mrand(int range) {
    return rand() % range;
}

// fill the contents of a 2-dimensional array with random number
void fill_random_numbers(Array* arr, int range, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < arr->size; i++) {
        arr->val[i] = mrand(range);
    }
}