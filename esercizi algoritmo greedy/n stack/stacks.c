#include "stacks.h"
#include <stdbool.h>
#include <ctype.h>

unsigned MaxSumNStack(Stack* stacks, size_t n) {

	unsigned* sum = calloc(n, sizeof(unsigned));

	//somma iniziale stack
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < stacks[i].m; j++)
		{
			sum[i] += stacks[i].elements[j];
		}
	}

	int tutti_uguali = false;
	while (!tutti_uguali) {

		tutti_uguali = true;
		unsigned max_sum = 0;
		unsigned min_sum = 100000;
		size_t max_idx = 0;
		for (size_t i = 0; i < n; i++)
		{
			//controllo che massimo e minimo sono uguali , se sì somme tutte uguali
			if (sum[i] > max_sum)
			{
				max_sum = sum[i];
				max_idx = i;
			}
			if (sum[i] < min_sum)
			{
				min_sum = sum[i];
			}
		}

		//se tutte uguali fermati
		if (max_sum == min_sum)
		{
			break;
		}

		if (stacks[max_idx].m > 0)
		{
			sum[max_idx] -= stacks[max_idx].elements[stacks[max_idx].m - 1]; // rimuovo elemento cima dalla somma
			stacks[max_idx].m--;
		}

		//controllo se ora tutte somme uguali
		for (size_t i = 1; i < n; i++)
		{
			if (sum[i] != sum[0]) { // sum[0] perchè tanto devono essere tutte uguali
				tutti_uguali = false;
				break;
			}
		}
	}
	unsigned sum_uguale = sum[0];
	free(sum);

	return sum_uguale;
}
//
//int main(void) {
//	unsigned s1[] = { 1, 1, 1, 2, 3 };     // somma 8
//	unsigned s2[] = { 2, 3, 4 };           // somma 9
//	unsigned s3[] = { 1, 4, 5, 2 };        // somma 12
//
//	Stack stacks[] = {
//		{s1, 5},
//		{s2, 3},
//		{s3, 4}
//	};
//
//	unsigned result = MaxSumNStack(stacks, 3);
//}