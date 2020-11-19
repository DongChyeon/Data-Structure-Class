#include <stdio.h>

// �迭 ��� ���
void print_array(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// ���� ����
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

// ���� ����
void insertion_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}	// ���� ������ ���ڰ� �� ���ں��� ���� ��� ��ĭ�� �о ����
		arr[j + 1] = key;
	}
}

// ���� ����
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
			}	// �� ���� ���� ���� �� ��ȯ
		}
	}
}

// ���� �Լ�
int main() {
	int arr[6] = { 1, 4, 3, 5, 9, 7 };

	printf("���� �� -> ");
	print_array(arr, 6);
	// ���� ����
	printf("���� �� -> ");
	selection_sort(arr, 6);
	print_array(arr, 6);

	printf("���� �� -> ");
	print_array(arr, 6);
	// ���� ����
	printf("���� �� -> ");
	insert_sort(arr, 6);
	print_array(arr, 6);
	
	printf("���� �� -> ");
	print_array(arr, 6);
	// ���� ����
	printf("���� �� -> ");
	bubble_sort(arr, 6);
	print_array(arr, 6);

	int arr2[1000];
	for (int i = 0; i < 1000; i++) {
		arr2[i] = rand() % 100;
	}
	insert_sort(arr2, 1000);

	return 0;
}