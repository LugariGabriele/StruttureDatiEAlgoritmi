#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//count numero totale pacchi dato che devo massimizzare numero
//in questo caso sol parziali non possono essere soluzioni

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int i, bool* curr, bool* best, int* numbest, int count, int sum) {

	if (i == pacchi_size) //foglia
	{
		if (count > *numbest && sum <= p)
		{
			*numbest = count;
			memcpy(best, curr, pacchi_size * sizeof(bool));
		}
		return; // torno indietro ricorsione
	}

	curr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, curr, best, numbest, count, sum);

	//includo pacco
	if (sum + pacchi[i] <= p) //pacco se aggiunto rietra in limite
	{
		curr[i] = 1;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, curr, best, numbest, count + 1, sum + pacchi[i]);
		curr[i] = 0;

	}


}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	bool* curr = calloc(pacchi_size, sizeof(bool));
	bool* best = calloc(pacchi_size, sizeof(bool));
	int numbest = 0;

	BabboNataleRec(pacchi, pacchi_size, p, 0, curr, best, &numbest, 0, 0);

	for (size_t j = 0; j < pacchi_size; j++)
	{
		printf("%d ", best[j]);
	}
	printf("\n");

	free(curr);
	free(best);

}
