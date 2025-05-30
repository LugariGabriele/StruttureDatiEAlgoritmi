#include <stdio.h>
#include <stdlib.h>




void TrovaNumEsagonali(int n, int max, int res) {

	res = res + 6 * n;

	if (res >= max)
	{
		return;
	}



	printf("%d ", res);

	TrovaNumEsagonali(n + 1, max,res);
}


int main(int argc, char** argv) {
	if (argc != 2)
	{
		return 1;
	}

	int max = atoi(argv[1]);
	if (max <= 0)
	{
		return 1;
	}


	TrovaNumEsagonali(0, max, 1);

	return 0;
}