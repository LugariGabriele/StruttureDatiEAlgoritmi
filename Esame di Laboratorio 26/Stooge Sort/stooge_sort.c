#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include<stdio.h>

void StoogeSort(int* v, int start, int end) {

	if (v[start] > v[end])
	{
		int tmp = v[start];
		v[start] = v[end];
		v[end] = tmp;
	}

	int n = end - start + 1; // num elem
	if (n > 2) // tre o più elem
	{

		//calcolo 2/3
		int k = (int)ceil((double)n * 2.0 / 3.0);


		StoogeSort(v, start, start + k - 1); // primi 2/3
		StoogeSort(v, end - k + 1, end);     // ultimi 2/3
		StoogeSort(v, start, start + k - 1); // di nuovo primi 2/3


	}

}


void Stooge(int* vector, size_t vector_size) {

	if (vector == NULL || vector_size < 2) {
		return;
	}
	StoogeSort(vector, 0, (int)vector_size - 1);
}

//
//int main(void) {
//	int v[] = { 5, 3, 8, 4, 2, 7, 1, 6 };
//	size_t size = sizeof(v) / sizeof(v[0]);
//
//	printf("Array prima dell'ordinamento:\n");
//	for (size_t i = 0; i < size; ++i) {
//		printf("%d ", v[i]);
//	}
//	printf("\n");
//
//	Stooge(v, size);
//
//	printf("Array dopo Stooge Sort:\n");
//	for (size_t i = 0; i < size; ++i) {
//		printf("%d ", v[i]);
//	}
//	printf("\n");
//
//	return 0;
//}