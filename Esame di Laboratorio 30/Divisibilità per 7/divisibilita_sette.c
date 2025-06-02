#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool IsMultiple7(int n) {

	if (n==7||n==0)
	{
		return true;
	}

	if (n<10)
	{
		return false;
	}

	int n1 = n / 10;
	int n2 = n % 10;
	int new_n = abs(n1 - (n2 * 2));

	IsMultiple7(new_n);

}



int main(int argc, char** argv) {
	
	if (argc!=2)
	{
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}

	if (IsMultiple7(n))
	{
		printf("Multiplo di 7.");
	}
	else
	{
		printf("Non multiplo di 7.");
	}

	return 0;
}