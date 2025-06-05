#include <stdlib.h>
#include <stdio.h>


int Triangular(int n) {

	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return 1;
	}

	if (n==2)
	{
		return 3;
	}

	return 3 * Triangular(n - 1) - 3 * Triangular(n - 2) + Triangular(n - 3);
}


int main(int argc, char** argv) {


	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n<0)
	{
		return 1;
	}


	int n_triang = Triangular(n);
	printf("%d", n_triang);

	return 0;
}