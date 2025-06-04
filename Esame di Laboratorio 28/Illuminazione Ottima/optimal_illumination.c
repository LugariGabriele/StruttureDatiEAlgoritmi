#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_illuminated(int M, int R, const int* light, size_t light_size,
	const bool* sol) {

	bool* coperto = calloc(M, sizeof(bool)); // solo da 0 a M

	for (size_t i = 0; i < light_size; i++) {
		if (sol[i]) {
			int start = light[i] - R;
			int end = light[i] + R;
			if (start < 0) start = 0;
			if (end > M) end = M;
			for (int j = start; j < end; ++j) {
				coperto[j] = true;
			}
		}

	}


	for (int i = 0; i < M; ++i) {
		if (!coperto[i]) {
			free(coperto);
			return false;
		}
	}

	free(coperto);
	return true;
}

void OptimalIlluminationRec(int M, int R, const int* light, size_t light_size, bool* sol_ottima,
	bool* sol_curr, int idx, int n_LampOn, int* n_LampOn_Best, int* nsol) {

	if (idx == (int)light_size) // controllato tutto array
	{
		if (is_illuminated(M, R, light, light_size, sol_curr)) { //sol ammissibile

			if (*nsol == 0 || n_LampOn < *n_LampOn_Best) // prima sol oppure ne ho trovata una migliore
			{
				(*nsol)++;
				*n_LampOn_Best = n_LampOn;

				//copio vcurr come migliore
				for (size_t i = 0; i < light_size; i++)
				{
					sol_ottima[i] = sol_curr[i];
				}
			}
		}
		return;
	}

	sol_curr[idx] = 0;
	OptimalIlluminationRec(M, R, light, light_size, sol_ottima, sol_curr, idx + 1, n_LampOn, n_LampOn_Best, nsol);
	sol_curr[idx] = 1;
	OptimalIlluminationRec(M, R, light, light_size, sol_ottima, sol_curr, idx + 1, n_LampOn + 1, n_LampOn_Best, nsol);
	sol_curr[idx] = 0;


}


bool* OptimalIllumination(int M, int R, const int* light,
	size_t light_size) {


	bool* sol_ottima = malloc(light_size * sizeof(bool));
	bool* sol_curr = malloc(light_size * sizeof(bool));
	int n_LampOn = 0;
	int n_LampOn_Best = 10000;
	int nsol = 0;


	OptimalIlluminationRec(M, R, light, light_size, sol_ottima, sol_curr, 0, n_LampOn, &n_LampOn_Best, &nsol);

	if (nsol == 0)
	{
		free(sol_curr);
		free(sol_ottima);
		return NULL;
	}



	free(sol_curr);
	return sol_ottima;
}
//
//int main(void) {
//
//	int light[] = { 2,7, 9 };
//	int M = 10, R = 3;
//	size_t size = sizeof(light) / sizeof(light[0]);
//
//	bool* result = OptimalIllumination(M, R, light, size);
//	if (result == NULL) {
//		printf("NULL\n");
//	}
//	else {
//		for (size_t i = 0; i < size; i++) {
//			printf("%d ", result[i]);
//		}
//		printf("\n");
//		free(result);
//	}
//	return 0;
//}