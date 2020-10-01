#include <stdio.h>
#include "sort.h"

int main() {
    Array a;

    long start, end;

    a = make_array(100);
    fill_random_numbers(a, 10000);
    start = get_runtime();
    print_array(a, "Before sorting");
    selection_sort(a);
    end = get_runtime();
    print_array(a, "After selection sort");
    printf("Duration of time : %ld ms\n\n", end - start);

    fill_random_numbers(a, 1000);
    start = get_runtime();
    print_array(a, "Before sorting");
    insert_sort(a);
    end = get_runtime();
    print_array(a, "After insert sort");
    printf("Duration of time : %ld ms\n\n", end - start);

    fill_random_numbers(a, 1000);
    start = get_runtime();
    print_array(a, "Before sorting");
    bubble_sort(a);
    end = get_runtime();
    print_array(a, "After bubble sort");
    printf("Duration of time : %ld ms\n\n", end - start);

    return 0;
}