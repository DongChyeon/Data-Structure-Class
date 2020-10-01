#ifndef _SORT_

#define _SORT_

typedef struct {
    int *val;
    int size;
} Node;

long get_runtime(void);
void print_array(Node* node, char *msg);
void swap(int *a, int *b);
void selection_sort(Node* node);
void insert_sort(Node* node);
void bubble_sort(Node* node);
void fill_random_numbers(Node* node, int range);

#endif