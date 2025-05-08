#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void GolaCrestaRec(size_t n,int *vcurr,int i,int  num_max,int *nsol) {

	if (i==n) // arrivato a fine dell insieme
	{
		for (int j = 0; j < n-2; j++) {
			
			if (!((vcurr[j]<vcurr[j+1] && vcurr[j+1]>vcurr[j+2]) || (vcurr[j]>vcurr[j + 1] && vcurr[j + 1]<vcurr[j + 2])))
			{
				//sol non valida
				return;

			}
		}

		printf("(");
		for (int k = 0; k < n-1; k++)
		{
			printf("%d, ", vcurr[k]);
		}
		printf("%d), ", vcurr[n - 1]);
		(*nsol)++;
		return;
	}



	for (int j = 0; j < num_max; j++)
	{
		vcurr[i] = j;
		GolaCrestaRec(n, vcurr, i + 1, num_max, nsol);
	}
}

int  GolaCresta(size_t n) {

	if (n < 3)
	{
		return;
	}


	int num_max = 3;
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));
	GolaCrestaRec(n, vcurr, 0, num_max,&nsol);

	free(vcurr);
	return nsol;
}

int main(void) {
	int s = GolaCresta(3);
	return 0;
}