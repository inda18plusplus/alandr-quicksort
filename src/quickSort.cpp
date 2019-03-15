//
// Created by lunar on 15/03/19.
//

#include "quickSort.hpp"

void init() {

}

void swapElements(int *arr, int i1, int i2) {
	int tmp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = tmp;
}

void sortRange(int* arr, int start, int end) {

	if(end - start <= 1) {
		return;
	}

	if(end - start == 2)
		if(arr[start] > arr[start + 1])
			swapElements(arr, start, start + 1);

	const int pivot = start;
	const int pivotVal = arr[pivot];

	int swap = start + 1;
	for (int i = start + 1; i < end; ++i) {
		if(arr[i] < pivotVal) {
			swapElements(arr, i, swap++);
		}
	}

	swapElements(arr, start, --swap);

	sortRange(arr, start, swap);
	sortRange(arr, swap + 1, end);

}

void qs(int* arr, int len) {
	sortRange(arr, 0, len);
}