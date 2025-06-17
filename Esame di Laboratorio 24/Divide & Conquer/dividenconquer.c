#include <stdio.h>
#include <stdlib.h>


int DivideEtImpera(int n) {

	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	

	return (DivideEtImpera(n / 2) + DivideEtImpera((n+1) / 2) + n);
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


	int num = DivideEtImpera(n);
	printf("%d", num);

	return 0;
}