#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool IsMultipleRec(int n) {

	if (n < 10) // ho numero ad una cifra
	{
		if (n == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	int pari_sum = 0;
	int dispari_sum = 0;
	int i = 1;

	// scompongo il numero
	while (n > 0) {
		int cifra = n % 10;

		if (i % 2 == 0) {
			pari_sum += cifra;
		}
		else {
			dispari_sum += cifra;
		}
		n /= 10;
		i++;
	}

	int diff = abs(dispari_sum - pari_sum);
	return IsMultipleRec(diff);
}

bool IsMultiple(int n) {
	return IsMultipleRec(n);
}


int main(int argc, char** argv) {

	if (argc != 2)
	{
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0)
	{
		return 1;
	}

	if (IsMultiple(n))
	{
		printf("Multiplo di 11.");
	}
	else
	{
		printf("Non multiplo di 11.");
	}

	return 0;
}