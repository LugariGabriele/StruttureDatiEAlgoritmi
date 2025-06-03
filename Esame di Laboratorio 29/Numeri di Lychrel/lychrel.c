#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int RevNum(int n) {

	int rev = 0;

	while (n > 0) {
		int digit = n % 10;
		rev = rev * 10 + digit;
		n /= 10;
	}

	return rev;
}


bool IsPalindorme(int n) {

	int rev = RevNum(n);
	return rev == n;
}



bool IsLychrel(int n, int i) {

	if (IsPalindorme(n))
	{
		return true;
	}

	if (i == 0)
	{
		return false;
	}

	int n_rev = RevNum(n);
	int new_n = n + n_rev;

	IsLychrel(new_n, i - 1);

}

int main(int argc, char** argv) {

	if (argc != 3)
	{
		return 1;
	}

	int n = atoi(argv[1]);
	int i = atoi(argv[2]);

	if (n < 0)
	{
		return 1;
	}

	if (!IsLychrel(n, i))
	{
		printf("Lychrel");
	}
	else
	{
		printf("Non di Lychrel");
	}

	return 0;
}