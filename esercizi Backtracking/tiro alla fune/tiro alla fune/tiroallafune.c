#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void TiroAllaFuneRec(int* arr, int n, int i,int*vcurr, int* vcurr1, int* vcurr2,int *vbest1,int*vbest2, int numeroinsieme1, int* best_diff, int curr_diff, int somma1, int somma2) {

	if (numeroinsieme1 == n/2)
	{
		for (int j = 0,v1=0,v2=0;  j < n;  j++) //riempio i due insiemi
		{
			if (vcurr[j]) //metto a 1 in v curr quelli che vanno in insieme 1
			{
				vcurr1[v1] = arr[j];
				v1++;
			}
			else
			{
				vcurr2[v2] = arr[j];
				v2++;
			}
		}
		//sommo i componenti sottoinsiemi
		for (int d = 0; d < n / 2; d++)
		{
			somma1 += vcurr1[d];
		}
		for (int l = 0; l < n - n / 2; l++)
		{
			somma2 +=  vcurr2[l];
		}

		curr_diff = abs(somma1 - somma2);

		if (curr_diff<*best_diff)
		{
			*best_diff = curr_diff;
			memcpy(vbest1, vcurr1, (n / 2) * sizeof(int));
			memcpy(vbest2, vcurr2, (n- n / 2) * sizeof(int));
		}
		return;
	}

	if (i==n)
	{
		return;
	}

	vcurr[i] = 0;
	TiroAllaFuneRec(arr, n, i + 1, vcurr, vcurr1, vcurr2, vbest1, vbest2, numeroinsieme1, best_diff, curr_diff, somma1, somma2);

	vcurr[i] = 1;
	TiroAllaFuneRec(arr, n, i + 1, vcurr, vcurr1, vcurr2, vbest1, vbest2, numeroinsieme1 + 1, best_diff, curr_diff, somma1, somma2); //incremento numinsieme1
	vcurr[i] = 0;

}

	
void TiroAllaFune(int* arr, int n) {
	
	int* vcurr = calloc(n, sizeof(int));
	int* vcurr1 = malloc(n / 2 * sizeof(int));
	int* vcurr2 = malloc((n - n / 2) * sizeof(int));
	int* vbest1 = malloc(n / 2 * sizeof(int));
	int* vbest2 = malloc((n - n / 2) * sizeof(int));
	int  best_diff = INT_MAX;

	TiroAllaFuneRec(arr, n, 0, vcurr, vcurr1, vcurr2, vbest1, vbest2, 0, &best_diff, 0, 0, 0);

	printf("{ ");
	for (int i = 0; i < (n / 2); i++)
	{
		printf("%d, ", vbest1[i]);
	}
	printf("}, ");

	printf("{ ");
	for (int i = 0; i < (n - n / 2); i++)
	{
		printf("%d, ", vbest2[i]);
	}
	printf("},");
	return;
}

int main(int argc, char* argv[])
{
	int n = argc - 1;
	int* arr = malloc(n * sizeof(int));
	for (size_t i = 0, j = 1; i < n; i++, j++)
	{
		arr[i] = atoi(argv[j]);
	}

	TiroAllaFune(arr, n);
	return 0;
}
