#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BinarySumRec(int pos, int n, int* bin, int* sol) {
	
	if (pos == n) // array pieno
	{
		int half = n / 2;
		int sum1 = 0;
		int sum2 = 0;

		//conto somma
		for (int i = 0; i < half; ++i)
		{
			sum1 += bin[i];
		}

		for (int i = n - half; i < n;++i)
		{
			sum2 += bin[i];
		}

		if (sum1==sum2)		//sol giusta
		{
			//stampo
			for (int j = 0; j < n; j++)
			{
				printf("%d", bin[j]);
			}
			printf("\n");
			(*sol)++;
		}
		return;
	}

	bin[pos] = 0;
	BinarySumRec(pos + 1, n, bin, sol);
	bin[pos] = 1;
	BinarySumRec(pos + 1, n, bin, sol);
	bin[pos] = 0;
}


int BinarySum(int n) {

	if (n <= 0)
	{
		return 0;
	}

	int* bin = calloc(n, sizeof(int));
	int sol = 0;

	BinarySumRec(0, n, bin, &sol);
	free(bin);

	return sol;
}


//int main(void) {
//
//	int n = 5;
//	int nsol = BinarySum(n);
//	return 0;
//}