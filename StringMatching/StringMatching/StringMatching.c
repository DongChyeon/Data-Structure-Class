#include <stdio.h>

int stringMatching(char* str, char* substr) {
	int last_str = strlen(str) - 1;
	int last_substr = strlen(substr) - 1;

	for (int i = 0; i < last_str; i++) {
		if (str[i + last_substr] == substr[last_substr]) {
			int start_s = i;
			int j = 0;
			while (str[start_s + j] == substr[j]) {
				j++;
				if (j = last_substr) return i;
			}
		}
	}
	return -1;
}	// str���� substr�� �ִ� ���� �ε����� ��ȯ�ϴ� �Լ�

int main() {
	char str[15] = "I am a student";
	char substr[8] = "student";

	printf("%d", stringMatching(str, substr));
}