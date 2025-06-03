#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int* SolarCut(int A, size_t* sol_size) {

	int* result = NULL;
	size_t capacity = 10; //dim iniziale del vettore
	*sol_size = 0;

	result = malloc(capacity * sizeof(int));

	while (A > 0) {

		int side = sqrt(A);
		int square = side * side;


		//aumento capcaità se serve
		if (*sol_size >= capacity) {
			capacity *= 2;
			int* temp = realloc(result, capacity * sizeof(int));

			result = temp;
		}

		result[(*sol_size)++] = square;
		A -= square;
	}

	result = realloc(result, *sol_size * sizeof(int));
	return result;
}

//
//int main(void) {
//
//	int A = 12;
//	size_t sol_size;
//
//	int* result = SolarCut(A, &sol_size);
//	printf("Suddivisione in pannelli per area %d m^2:\n", A);
//	for (size_t i = 0; i < sol_size; ++i) {
//		printf("%d ", result[i]);
//	}
//	printf("\nTotale pannelli: %zu\n", sol_size);
//
//	free(result);  
//	return 0;
//
//}
