#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int SubsetEqualRec(int n, int s, int i, int* nsol, bool* vcurr, int scurr) {

	if (scurr == s)
	{
		(*nsol)++;
		printf("{ ");
		for (size_t j = 1; j <= n; j++)
		{
			if (vcurr[j]) {
				printf("%d ", j);
			}
		}
		printf("}, ");
		return;
	}

	if (i>n)
	{
		return;
	}


	//scelta del valore i-esimo (da i a n compreso)
	//in qiesto caso i corrisponde al numero che scelgo se prendere o no
	if (scurr + i <= s)
	{
		vcurr[i] = true;
		SubsetEqualRec(n, s, i + 1, nsol, vcurr, scurr + i);
		vcurr[i] = false;
	}

	//in ogni caso proseguo la ricerca senza usare l'elemento di valore i 
	SubsetEqualRec(n, s, i + 1, nsol, vcurr, scurr);


}

int SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0)
	{
		return 0;
	}

	int nsol = 0;
	bool* vcurr = calloc(n + 1, sizeof(bool));

	SubsetEqualRec(n, s, 1, &nsol, vcurr, 0); // per comodità i parte da 1 dato che insieme vuoto mai soluzione


	free(vcurr);

	return nsol;
}

int main(void) {
	int s;
	s = SubsetEqual(4, 6);
}