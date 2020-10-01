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

// 메시지와 함께 Node 출력
void print_array(Node* node, char* msg) {
    printf("%s\n", msg);
    for (int i = 0; i < node[0].size; i++) {
        printf("%d ", node[i].val);
    }
    printf("\n");
}

// 두 원소 교환
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 선택 정렬
void selection_sort(Node* node) {
    for (int i = 0; i < node[0].size - 1; i++) {
        int least = i;
        for (int j = i + 1; j < node[0].size; j++) {
            if (node[j].val < node[least].val) {
                least = j;
            }
        }
        swap(&node[i].val, &node[least].val);
    }
}

// 삽입 정렬
void insert_sort(Node* node) {
    for (int i = 1; i < node[0].size; i++) {
        Node key = node[i];
        int j = i - 1;
        while (j >= 0 && node[j].val > key.val) {
            node[j + 1].val = node[j].val;
            j--;
        }
        node[j + 1].val = key.val;
    }
}

// 버블 정렬
void bubble_sort(Node* node) {
    int isSorted = 0;

    for (int i = node[0].size - 1; i > 0 && !isSorted; i--) {
        isSorted = 1;
        for (int j = 0; j < i; j++) {
            if (node[j].val > node[j + 1].val) {
                swap(&node[j].val, &node[j + 1].val);
                isSorted = 0;
            }
        }
    }
}

int mrand(int range){
    return rand() % range;
}

// 랜덤한 수로 Node 채우기
void fill_random_numbers(Node* node, int range) {
    for (int i = 0; i < node[0].size; i++) {
        node[i].val = mrand(range);
    }
}