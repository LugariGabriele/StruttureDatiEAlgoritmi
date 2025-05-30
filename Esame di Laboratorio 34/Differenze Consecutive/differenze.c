#include <stdlib.h>
#include <math.h>
#include<stdio.h>

#define MAX_RESULT 1000

void DifferenzeRec(int pos, int n, int k, int num, int* res, size_t* count,size_t *capacity) {
	
	if (pos==n)  // ho numero di n cifre
	{
		if (*count>= *capacity)
		{
			*capacity *= 2;
			res = realloc(res,(*capacity) * sizeof(int));
		}
		res[*count] = num;
		(*count)++;
		return;
	}

	int last_digit = num % 10;

	//provo le due cifre valide che rispettano la differenza assoluta k
	for (int j = 0; j <=9; ++j)
	{
		int diff = abs(last_digit - j);
		if (diff== k)
		{
			DifferenzeRec(pos + 1, n, k, num * 10 + j, res, count,capacity);
		}
	}
}



int* Differenze(int n, int k, size_t* v_len) {
	if (n<=0 || k<0 )
	{
		*v_len = 0;
		return NULL;
	}

	size_t capacity = MAX_RESULT;
	int* result = malloc(sizeof(int) * capacity);
	*v_len = 0;

	//per ogni cifra iniziale da 1 a 9
	int start = (n > 1) ? 1 : 0; // fatto per evitare 070 ...
	for (int i = start; i <= 9; ++i)
	{
		DifferenzeRec(1, n, k, i, result, v_len,&capacity);
	}

	if (*v_len==0)
	{
		free(result);
		return NULL;
	}

	result = realloc(result, (*v_len) * sizeof(int));
	return result;
}

// int main(void) {
// 	int n = 3;
// 	int k = 12;
// 	size_t len = 0;

// 	int* risultati = Differenze(n, k, &len);
// 	if (risultati== NULL)
// 	{
// 		printf("nessun risultato valido.\n");
// 		return 0;
// 	}

// 	printf("risultati (%zu): \n", len);
// 	for (size_t i = 0; i < len; i++)
// 	{
// 		printf("%d ", risultati[i]);
// 	}
// 	printf("\n");

// 	free(risultati);
// 	return 0;
// }