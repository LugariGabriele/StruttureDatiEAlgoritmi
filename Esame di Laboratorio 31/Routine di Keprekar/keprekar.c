#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int CompareChars(const void* a, const void* b) {
	int int_a = *(const char*)a;
	int int_b = *(const char*)b;
	return (int_a > int_b) - (int_a < int_b);
}

void GetNumbers(const char* digits, int* high, int* low) {
	char* digits_copy = malloc(4);
	memcpy(digits_copy, digits, 4);
	qsort(digits_copy, 4, sizeof(char), CompareChars); // Sort the digits
	char rev_digits[4] = { digits_copy[3], digits_copy[2], digits_copy[1], digits_copy[0] }; // Copy reversed
	char* endptr;
	*high = strtol(rev_digits, &endptr, 10);
	*low = strtol(digits_copy, &endptr, 10);
	free(digits_copy);
}

void int_to_digits(int n, char* digits) {
	digits[0] = (n / 1000) % 10 + '0';
	digits[1] = (n / 100) % 10 + '0';
	digits[2] = (n / 10) % 10 + '0';
	digits[3] = n % 10 + '0';
}

bool TutteCifreUguali(int n) {
	char digits[4];
	int_to_digits(n, digits);
	for (int i = 1; i < 4; i++) {
		if (digits[i] != digits[0]) {
			return false;
		}
	}
	return true;
}


void KaprekarRec(int n) {

	printf("%04d ", n);

	if (n == 6174)
	{
		return;
	}
	else
	{
		char digit[4];
		int_to_digits(n, digit);
		int high, low;
		GetNumbers(digit, &high, &low); // high ordine decrescente low crescente
		int next = high - low;
	
		KaprekarRec(next);
	}

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

	if (n >= 10000 || TutteCifreUguali(n))
	{
		printf("Invalid number");
		return 0;
	}

	KaprekarRec(n);
	return 0;
}