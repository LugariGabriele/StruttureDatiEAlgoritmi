#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//calcola prodotto di riga o colonna a seconda di bool
int CalcolaProdotto(int* griglia, int n, int index, bool isRiga) {

	int prod = 1;
	for (int i = 0; i < n; i++)
	{
		prod *= isRiga ? griglia[index * n + i] : griglia[i * n + index];
	}

	return prod;
}



bool VerificaProdottoUguale(int* griglia, int n) {

	int prod = CalcolaProdotto(griglia, n, 0, true); // prendo prodotto di pirma riga(tanto deve essere = )

	for (int i = 0; i < n; i++) {
		if (CalcolaProdotto(griglia, n, i, true) != prod ||
			CalcolaProdotto(griglia, n, i, false) != prod) {
			return false;
		}
	}
	return true;

}

bool Backtrack(int* soluzione, bool* usati, const int* s, int n, int idx) {

	if (idx == (n * n))
	{
		return VerificaProdottoUguale(soluzione, n);
	}

	for (int i = 0; i < n * n; i++)
	{
		if (!usati[i])
		{
			soluzione[idx] = s[i];
			usati[i] = true;

			if (Backtrack(soluzione, usati, s, n, idx + 1))
			{
				return true;
			}

			usati[i] = false;
		}

	}
	return false;

}

int* RisolviProdotto(int n, const int* s) {

	int* sol = malloc((n * n) * sizeof(int));
	bool* usati = calloc(n * n, sizeof(bool));

	if (Backtrack(sol, usati, s, n, 0)) {
		free(usati);
		return sol;
	}

	free(sol);
	free(usati);
	return NULL;
}
