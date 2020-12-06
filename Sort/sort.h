#include <iostream>
#include <stdbool.h>
#define MAX_SIZE 1024
using namespace std;

void printArray(int* arr, int n);
void makeRandomArray(int* arr, int n, int range);
void selectionSort(int* arr, int n);
void insertionSort(int* arr, int n);
void bubbleSort(int* arr, int n);
void heapSort(int *arr, int n);
void mergeSort(int *arr, int left, int right);
static void merge(int* arr, int left, int mid, int right);
void quickSort(int* arr, int left, int right);
int partition(int* arr, int left, int right);