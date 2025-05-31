#include <stdlib.h>
#include <stdio.h>

int* TaggedSort(const int* v, size_t v_size) {

	if (v_size == 0)
	{
		return NULL;
	}

	int* v_tagged = malloc(v_size * sizeof(int));


	for (size_t i = 0; i < v_size; ++i) {
		v_tagged[i] = i; // lo riempio con gli indici
	}

	for (size_t i = 0; i < v_size; i++)
	{
		int min_idx = i;
		for (size_t j = i + 1; j < v_size; j++)
		{
			if (v[v_tagged[j]] < v[v_tagged[min_idx]]) //elemento j esimo è minore di elementi con j minimo?
			{
				min_idx = j;
			}
		}

		//scambio gli indici
		if (min_idx!=i)
		{
			int tmp = v_tagged[i];
			v_tagged[i] = v_tagged[min_idx];
			v_tagged[min_idx] = tmp;
		}
	}
	return v_tagged;
}
//
//int main(void) {
//	int v[] = { 6, 3, 1, 4, 12, 24 };
//	size_t size = sizeof(v) / sizeof(v[0]);
//
//	int* tagged = TaggedSort(v, size);
//
//	printf("Vettore ordinato usando i tag:\n");
//	for (size_t i = 0; i < size; ++i) {
//		printf("%d ", v[tagged[i]]);
//	}
//	printf("\n");
//
//	free(tagged);
//	return 0;
//}