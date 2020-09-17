#include <stdio.h>

// 배열 요소 출력
void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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
	int arr[6] = { 1, 3, 4, 5, 9, 7 };
	printf("정렬 전 -> ");
	print_array(arr, 6);
	
	printf("정렬 후 -> ");
	bubble_sort(arr, 6);
	print_array(arr, 6);

	return 0;
}