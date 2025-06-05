#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double CalcPi(int n) {
	
	if (n==0)
	{
		return 4;
	}

	double sum = (4 * pow(-1, n)) / (2 * n + 1);
	sum = sum + CalcPi(n - 1);

	return sum;
}


int main(int argc, char** argv) {

	if (argc!=2)
	{
		return 1;
	}

	int n = atoi(argv[1]);
	if (n<0)
	{
		return 1;
	}

	double res = CalcPi(n);
	printf("%f", res);
	return 0;
}