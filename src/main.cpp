#include <array>
#include <cstdio>
#include <algorithm>
#include <random>

#include "quickSort.hpp"

int main() {

	int size;
	scanf("%d", &size);

	int* arr = new int[size];

	for (int i = 0; i < size; ++i) {
		scanf("%d", &arr[i]);
	}

	qs(arr, size);

	for (int i = 0; i < size - 1; ++i) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[size - 1]);

	return 0;
}