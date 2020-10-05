#include <stdio.h>
#include <time.h>
#include "sort.h"

int main() {
    unsigned int seed = time(NULL);
    long start, end;

    Array* a, * b, * c;
    a = make_array(112500);
    fill_random_numbers(a, 1000, seed);
    b = make_array(112500);
    fill_random_numbers(b, 1000, seed);
    c = make_array(112500);
    fill_random_numbers(c, 1000, seed);

    //print_array(a, "Before sorting");
    start = get_currentTime();
    selection_sort(a);
    end = get_currentTime();
    //print_array(a, "After selection sort");
    printf("Execution time : %ld msec\n\n", end - start);

    //print_array(b, "Before sorting");
    start = get_currentTime();
    insertion_sort(b);
    end = get_currentTime();
    //print_array(b, "After insertion sort");
    printf("Execution time : %ld msec\n\n", end - start);

    //print_array(c, "Before sorting");
    start = get_currentTime();
    bubble_sort(c);
    end = get_currentTime();
    //print_array(c, "After bubble sort");
    printf("Execution time : %ld msec\n\n", end - start);

    freeArray(a);
    freeArray(b);
    freeArray(c);

    return 0;
}