#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>

void CocktailSort(int* v, size_t v_size) {

	if (v == NULL || v_size < 2) {
		return;
	}

	int start = 0;
	int end = v_size - 1;

	bool swap = true;

	while (swap || end <= start) {

		swap = false;

		//fase da sx a dx
		for (size_t i = start; i < end; i++)
		{
			if (v[i] > v[i + 1]) {
				swap = true;
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}
		end--;

		if (!swap) // controllo così evito di dover fare altro ciclo
		{
			break;
		}


		swap = false;
		//fase dx a sx
		for (size_t i = end; i > start; i--)
		{
			if (v[i] < v[i - 1])
			{
				swap = true;
				int tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
			}
		}
		start++;
	}
}

int main(void) {

	int* v = malloc(5 * sizeof(int));
	v[0] = 3;
	v[1] = 6;
	v[2] = 2;
	v[3] = 4;
	v[4] = 8;

	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", v[i]);
	}

	printf("\n");

	CocktailSort(v, 5);
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", v[i]);
	}

	free(v);
}