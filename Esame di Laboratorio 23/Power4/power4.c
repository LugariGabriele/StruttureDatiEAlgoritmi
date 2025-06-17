#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool isPower4(int n, int res, int* i) {

	if (n <= 0 || res > n)
	{
		return false;
	}

	if (res == n)
	{
		return true;
	}

	res *= 4;
	(*i)++;
	isPower4(n, res, i);
}


int main(int argc, char** argv) {

	if (argc != 2)
	{
		return 1;
	}


	int n = atoi(argv[1]);
	int i = 0;
	if (isPower4(n, 1, &i)) {
		printf("4^%d = %d", i, n);
	}
	else
	{
		printf("!p4");
	}

	return 0;
}