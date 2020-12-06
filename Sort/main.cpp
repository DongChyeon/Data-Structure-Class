#include "sort.h"

int main() {
    int arr[10];

	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Selection sort" << endl; 
	selectionSort(arr, 6);
	printArray(arr, 10);
	cout << endl;

	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Insertion sort" << endl;
	insertionSort(arr, 6);
	printArray(arr, 10);
	cout << endl;
	
	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Bubble sort" << endl;
	bubbleSort(arr, 10);
	printArray(arr, 10);
	cout << endl;

	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Heap sort" << endl;
	heapSort(arr, 10);
	printArray(arr, 10);
	cout << endl;

	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Merge sort" << endl;
	mergeSort(arr, 0, 9);
	printArray(arr, 10);
	cout << endl;

	cout << "Before sorting" << endl;
	makeRandomArray(arr, 10, 20);
	printArray(arr, 10);
	cout << "Quick sort" << endl;
	quickSort(arr, 0, 9);
	printArray(arr, 10);
	cout << endl;

    return 0;
}