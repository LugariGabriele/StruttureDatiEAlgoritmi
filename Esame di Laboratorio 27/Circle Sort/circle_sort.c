#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool CircleSortRecursive(int* v, size_t left, size_t right) {

	if (left == right) {
		return false; // un solo elemento: nessuno scambio
	}

	bool swapped = false;
	size_t l = left;
	size_t r = right;


	while (l < r) {
		if (v[l] > v[r])
		{
			int tmp = v[l];
			v[l] = v[r];
			v[r] = tmp;
			swapped = true;
		}
		l++;
		r--;
	}

	// Caso dispari: confronta centro con quello dopo
	if (l == r && (r + 1 <= right) && v[l] > v[l + 1]) {
		int temp = v[l];
		v[l] = v[l + 1];
		v[l + 1] = temp;
		swapped = true;
	}

	// Ricorsione sui due sottovettori
	size_t mid = (left + right) / 2;
	bool left_swapped = CircleSortRecursive(v, left, mid);
	bool right_swapped = CircleSortRecursive(v, mid + 1, right);

	return swapped || left_swapped || right_swapped;
}

void CircleSort(int* v, size_t v_size) {

	if (v == NULL || v_size <= 1)
	{
		return;
	}

	while (CircleSortRecursive(v, 0, v_size - 1)) { //continua fino a che ritorna true(quindi fanno scambio precendete)

	}
}