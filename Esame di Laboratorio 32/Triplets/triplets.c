#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void TripletsRec(const int* v, size_t v_size, int n, int idx, int* vcurr, int* nsol, int sommacurr, int n_val) {

	
	if (n_val == 3) // ho terna
	{
		//controllo che somma sia <= n
		if (sommacurr <= n)
		{
			(*nsol)++;
			int count = 1;
			for (int i = 0; i < (int)v_size; i++)
			{

				if (vcurr[i]) {
					count++;
					if (count <= 3)
					{
						printf("%d, ", v[i]);
					}
					else
					{
						printf("%d", v[i]);
					}
				}
			}
			printf("\n");

		}
		return;
	}

	if (idx >= (int)v_size) //controllo per ciclo non infinito
	{
		return;
	}


	vcurr[idx] = 0;
	TripletsRec(v, v_size, n, idx + 1, vcurr, nsol, sommacurr, n_val);
	vcurr[idx] = 1;
	TripletsRec(v, v_size, n, idx + 1, vcurr, nsol, sommacurr + v[idx], n_val + 1);
	vcurr[idx] = 0;
}

int Triplets(const int* v, size_t v_size, int n) {

	if (v_size < 3) return 0;

	int* vcurr = malloc(v_size * sizeof(int));
	int nsol = 0;

	TripletsRec(v, v_size, n, 0, vcurr, &nsol, 0, 0);


	free(vcurr);
	return nsol;
}


//int main(void) {
//
//
//	int v[] = { 1,3,2,5,7,6,4 };
//	int n = 9;
//	size_t v_size = sizeof(v) / sizeof(v[0]);
//
//	int n_res = Triplets(v, v_size, n);
//
//	return 0;
//}