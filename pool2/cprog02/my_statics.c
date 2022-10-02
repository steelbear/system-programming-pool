#include "my_statics.h"

int average_arr(int* arr, int length) {
	int total = 0;

	for(int i = 0; i < length; i++) {
		total += arr[i];
	}

	return total / length;
}

int maximum_arr(int* arr, int length) {
	int maximum = arr[0];

	for(int i = 1; i < length; i++) {
		if(maximum < arr[i]) {
			maximum = arr[i];
		}
	}

	return maximum;
}

int minimum_arr(int* arr, int length) {
	int minimum = arr[0];

	for(int i = 1; i < length; i++) {
		if(minimum > arr[i]) {
		       minimum = arr[i];
		}
	}

	return minimum;
}	

int argmax_arr(int* arr, int length) {
	int argmax = 0;

	for(int i = 1; i < length; i++) {
		if (arr[argmax] < arr[i]) {
			argmax = i;
		}
	}

	return argmax;
}

void sort_arr(int* arr, int length) {
	for(int i = length - 1; i > 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
