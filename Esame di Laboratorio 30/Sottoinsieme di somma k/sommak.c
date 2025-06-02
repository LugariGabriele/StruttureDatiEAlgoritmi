#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void SommaKRec(int n, int k, int* ins, bool* vcurr, int sommacurr, int idx, int* nsol) {

	if (idx == n) // finito di controllare tutto array
	{
		if (sommacurr == k) // sol
		{
			(*nsol)++;

			printf("{");
			for (size_t i = 0; i < n; i++)
			{
				if (vcurr[i]) {

					printf("%d, ", ins[i]);

				}
			}
			printf("},");
		}

		return;
	}


	if (idx >= n) // controllo overflow
	{
		return;
	}

	vcurr[idx] = 0;
	SommaKRec(n, k, ins, vcurr, sommacurr, idx + 1, nsol);
	vcurr[idx] = 1;
	SommaKRec(n, k, ins, vcurr, sommacurr + ins[idx], idx + 1, nsol);
	vcurr[idx] = 0;

}

int SommaK(int n, int k) {


	bool* vcurr = malloc(n * sizeof(bool));
	int* ins = malloc(n * sizeof(int));
	// riempio insieme con i numeri da 1 a n
	for (int i = 0; i < n; i++)
	{
		ins[i] = i + 1;
	}

	int nsol = 0;
	SommaKRec(n, k, ins, vcurr, 0, 0, &nsol);

	free(ins);
	free(vcurr);

	return nsol;
}

//int main(void) {
//
//
//	int n = 6;
//	int k = 0;
//
//	int sol = SommaK(n, k);
//}