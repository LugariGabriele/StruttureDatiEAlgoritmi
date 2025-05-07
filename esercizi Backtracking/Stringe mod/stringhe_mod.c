#include <stdio.h>
#include <stdlib.h>


void BacktrackStrModRec(int n, int k, int i, char* vcurr) {
	if (i == k)
	{
		printf("{");
		for (int j = 0; j < k; j++)
		{
			printf("%c", vcurr[j]);
		}
		printf("}, ");
		return;
	}


	for (char c = 'a'; c < 'a' + n; c++)
	{
		vcurr[i] = c;
		BacktrackStrModRec(n, k, i + 1, vcurr);
	}
}

void BacktrackStrMod(int n, int k) {

	if (k <= 0 || k > 26 || n <= 0)
	{
		return;
	}

	char* vcurr = malloc(k * sizeof(char));

	BacktrackStrModRec(n, k, 0, vcurr);

	free(vcurr);
}

int main(void) {

	BacktrackStrMod(26, 1);
}