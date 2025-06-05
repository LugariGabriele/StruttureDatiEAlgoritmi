#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void OptimalSubarrayRec(const int* v, size_t n, int start, int end, int* sum_best, int sum_curr) {

	if (end > (int)n)
	{
		return;
	}

	if (sum_curr > *sum_best)
	{
		*sum_best = sum_curr;
	}

	if (end < (int)n)
	{
		//provo a espandere il vettore aggiungendo un elem
		OptimalSubarrayRec(v, n, start, end + 1, sum_best, sum_curr + v[end]);
	}

}

int OptimalSubarray(const int* v, size_t n) {

	if (n == 0 || v == NULL) return 0;


	int sum = 0;

	//provo a farlo partire da tutti gli elem del vettore
	for (int i = 0; i < (int)n; i++)
	{
		OptimalSubarrayRec(v, n, i, i, &sum, 0);
	}

	return sum;
}

//int main(void) {
//
//	int v[] = { -1, -2, -3, -4, -5, -6 };
//	int sum = OptimalSubarray(v, 6);
//}