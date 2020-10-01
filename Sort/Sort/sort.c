#include <stdio.h>

// 배열 요소 출력
void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// 선택 정렬
void selection_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[least]) {
				least = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;
	}
}

// 삽입 정렬
void insert_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}	// 새로 삽입할 숫자가 앞 숫자보다 작을 경우 한칸씩 밀어서 삽입
		arr[j + 1] = key;
	}
}

// 버블 정렬
void bubble_sort(int* arr, int n) {
	int isSorted = 0;

	for (int i = n - 1; i > 0 && !isSorted; i--) {
		isSorted = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSorted = 0;
			}	// 앞 뒤의 값을 비교한 후 교환
		}
	}
}

// 메인 함수
int main() {
	int arr[6] = { 1, 4, 3, 5, 9, 7 };

	printf("정렬 전 -> ");
	print_array(arr, 6);
	// 선택 정렬
	printf("정렬 후 -> ");
	selection_sort(arr, 6);
	print_array(arr, 6);

	printf("정렬 전 -> ");
	print_array(arr, 6);
	// 삽입 정렬
	printf("정렬 후 -> ");
	insert_sort(arr, 6);
	print_array(arr, 6);
	
	printf("정렬 전 -> ");
	print_array(arr, 6);
	// 버블 정렬
	printf("정렬 후 -> ");
	bubble_sort(arr, 6);
	print_array(arr, 6);

	int arr2[1000];
	for (int i = 0; i < 1000; i++) {
		arr2[i] = rand() % 100;
	}
	insert_sort(arr2, 1000);

	return 0;
}