#include "sort.h"
#include "minHeap.h"

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void makeRandomArray(int* arr, int n, int range) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % range + 1;
	}
}

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[least]) {
				least = j;
			}
		}
        swap(arr[i], arr[least]);
	}
}

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void bubbleSort(int* arr, int n) {
    bool isSorted = false;

	for (int i = n - 1; i > 0 && !isSorted; i--) {
		isSorted = true;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSorted = false;
			}
		}
	}
}

void heapSort(int *arr, int n) {
	MinHeap heap;

	for (int i = 0; i < n; i++)
		heap.insert(arr[i]);
	for (int i = 0; i < n; i++)
		arr[i] = heap.remove();
} 

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left+right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

static void merge(int* arr, int left, int mid, int right) {
	int i, j, l;
	int k = left;
	static int sorted[MAX_SIZE];

	for (i = left, j = mid + 1; i <= mid && j <= right; ) {
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		} else {
			sorted[k++] = arr[j++];
		}
	}
	if (i > mid) {
		for (l = j; l <= right; l++, k++) {
			sorted[k] = arr[l];
		}
	} else {
		for (l = i; l <= mid; l++, k++) {
			sorted[k] = arr[l];
		}
	}

	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void quickSort(int* arr, int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		quickSort(arr, left, q - 1);
		quickSort(arr, q + 1, right);
	}
}

int partition(int* arr, int left, int right) {
	int low = left;
	int high = right + 1;
	int pivot = arr[left];

	do {
		do {
			low++;
		} while (low <= right && arr[low] < pivot);
		do {
			high--;
		} while (high >= left && arr[high] > pivot);

		if (low < high) swap(arr[low], arr[high]);
	} while (low < high);
	
	swap(arr[left], arr[high]);
	return high;
}