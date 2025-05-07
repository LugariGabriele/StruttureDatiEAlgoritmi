#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


void StepsRec(int n, int i, int* vcurr, int* nsol) {

	if (n == 0) //sono arrivato in cima quindi stampo sol
	{
		printf("[");
		for (int j = 0; j < i - 1; j++) {
			printf("%d,", vcurr[j]);
		}
		printf("%d]",vcurr[i-1]);
		(*nsol)++;
		return;
	}
	
	for (int j = 1; j <= 3; j++)
	{
		if (n >= j) {
			vcurr[i] = j;
			StepsRec(n - j, i + 1, vcurr, nsol);
		}
	}

}

int Steps(int n) {

	if (n <= 0)
	{
		return 0;
	}

	int nsol = 0;
	int* vcurr = malloc(n * sizeof(int));

	StepsRec(n, 0, vcurr, &nsol);
	free(vcurr);

	return nsol;
}

int main(void) {

	int s;
	s = Steps(4);
}