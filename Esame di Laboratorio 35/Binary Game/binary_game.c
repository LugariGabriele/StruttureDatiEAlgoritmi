#include <stdlib.h>


int maxDiff = -2147483648; // Min int


void compute_x_y(const int* arr, size_t n) {
	int x = 0, y = 0;
	for (size_t i = 0; i < 2 * n; i += 2)
		x ^= (arr[i] & arr[i + 1]); // ^ XOR

	for (size_t i = 2 * n; i < 4 * n; i += 2)
		y ^= (arr[i] & arr[i + 1]);

	int diff = x - y;
	if (diff > maxDiff)
		maxDiff = diff;
}

void swap(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}

void backtrack(int* arr, int start, size_t total, size_t n) {
	if (start == total) { // ho fatto permutazione per tutto array
		compute_x_y(arr, n);
		return;
	}

	for (size_t i = start; i < total; ++i) {
		swap(&arr[start], &arr[i]); // provo permutazioni
		backtrack(arr, start + 1, total, n);
		swap(&arr[start], &arr[i]);
	}
}

int BinaryGame(const int* nums, size_t n) {

	size_t size = 4 * n;
	int* copy = malloc(size * sizeof(int));
	for (size_t i = 0; i < size; i++)
	{
		copy[i] = nums[i];
	}

	maxDiff = -2151515;

	backtrack(copy, 0, size, n);

	free(copy);
	return maxDiff;
}
