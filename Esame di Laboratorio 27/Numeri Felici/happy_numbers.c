#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


bool IsHappy(int n) {

	if (n == 4 || n == 0)
	{
		return false;
	}

	if (n == 1)
	{
		return true;
	}

	int sum = 0;
	while (n > 0) {

		sum += pow((n % 10), 2);
		n /= 10;
	}

	return IsHappy(sum);
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

	if (IsHappy(n))
	{
		printf("Felice");
	}
	else
	{
		printf("Infelice");
	}


	return 0;
}