#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

long get_runtime(void)
{
    clock_t start;
    start = clock();
    return((long)((double)start * 1000.0 / (double)CLOCKS_PER_SEC));
}

int *array(int size) {
    int *array = (int *) malloc(sizeof(int) * size);

    return array;
}

Array make_array(int size) {
    Array temp;
    temp.size = size;
    temp.val = array(size);

    return temp;
}

void freeArray(Array array) {
    free(array.val);
}

// 두 원소 교환
void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

// 선택 정렬
void selection_sort(Array array) {
    for (int i = 0; i < array.size - 1; i++) {
        int least = i;
        for (int j = i + 1; j < array.size; j++) {
            if (array.val[j] < array.val[least]) {
                least = j;
            }
        }
        swap(&array.val[i], &array.val[least]);
    }
}

// 삽입 정렬
void insert_sort(Array array) {
    for (int i = 1; i < array.size; i++) {
        int key = array.val[i];
        int j = i - 1;
        while (j >= 0 && array.val[j] > key) {
            array.val[j + 1] = array.val[j];
            j--;
        }
        array.val[j + 1] = key;
    }
}

// 버블 정렬
void bubble_sort(Array array) {
    int isSorted = 0;

    for (int i = array.size - 1; i > 0 && !isSorted; i--) {
        isSorted = 1;
        for (int j = 0; j < i; j++) {
            if (array.val[j] > array.val[j + 1]) {
                swap(&array.val[j], &array.val[j + 1]);
                isSorted = 0;
            }
        }
    }
}

// 메시지와 함께 Array 출력
void print_array(Array array, char* msg) {
    printf("%s\n", msg);
    for (int i = 0; i < array.size; i++) {
        printf("%d \t", array.val[i]);
    }
    printf("\n\n");
}

// 0부터 range - 1까지의 랜덤한 수 발생
int mrand(int range){
    return rand() % range;
}

// 랜덤한 수로 Array 채우기
void fill_random_numbers(Array arr, int range) {
    for (int i = 0; i < arr.size; i++) {
        arr.val[i] = mrand(range);
    }
}