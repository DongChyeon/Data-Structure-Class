#ifndef _SORT_

#define _SORT_

typedef struct {
    int* val;
    int size;
} Array;

long get_currentTime(void);

int* vector(int size);
Array* make_array(int size);

void freeVector(int* vec);
void freeArray(Array* arr);

void swap(int* val1, int* val2);
void selection_sort(Array* arr);
void insertion_sort(Array* arr);
void bubble_sort(Array* arr);

void print_array(Array* arr, char* msg);
int mrand(int range);
void fill_random_numbers(Array* arr, int range, unsigned int seed);

#endif