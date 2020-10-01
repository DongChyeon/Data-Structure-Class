#ifndef _SORT_

#define _SORT_

typedef struct {
    int *val;
    int size;
} Array;

long get_runtime(void);

int *array(int size);
Array make_array(int size);

void freeArray(Array array);

void swap(int *val1, int *val2);
void selection_sort(Array array);
void insert_sort(Array array);
void bubble_sort(Array array);

void print_array(Array array, char *msg);
int mrand(int range);
void fill_random_numbers(Array array, int range);

#endif