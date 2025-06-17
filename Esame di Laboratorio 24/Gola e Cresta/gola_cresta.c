#include <stdio.h>
#include <stdlib.h>


void GolaCrestaBackTrack(size_t n, int* vcurr, int idx, int num_curr) {

	if (num_curr == (int)n) // ho riempito array
	{

		//stampo sol
		printf("(%d", vcurr[0]);

		for (int i = 1; i < num_curr; i++)
		{
			printf(", %d", vcurr[i]);
		}
		printf("), ");

		return;
	}





	for (size_t num = 0; num < 3; num++) //0 1 2
	{
		vcurr[idx] = num;

		//controllo se regola va bene (controllo solo se ho almeno 3 elem)
		if (idx >= 2)
		{
			int a = vcurr[idx - 2]; // xi
			int b = vcurr[idx - 1]; //xi+1
			int c = vcurr[idx]; // xi+2

			// Se la terna non soddisfa le condizioni, scarto
			if (!((a < b && b > c) || (a > b && b < c)))
				continue;
		}

		GolaCrestaBackTrack(n, vcurr, idx + 1, num_curr + 1);
	}

}

void GolaCresta(size_t n) {

	if (n < 3)
	{
		return;
	}


	int* vcurr = malloc(n * sizeof(int));
	GolaCrestaBackTrack(n, vcurr, 0, 0);

	free(vcurr);
}

