#include <iostream>

arrayMax(int list[], int size, int max) {
	int temp_max = max;
	if (size == 0) {
		return temp_max;
	}
	if (list[size - 1] > temp_max) {
		temp_max = A[size - 1];
	}
	arrayMax(list, size - 1, temp_max);
}

int main() {
	int list[];
	arrayMax(int list[], int 0, 0)
}