#include <stdbool.h>
#include <stdlib.h>

int* CalcolaDivisori(int n, int* n_div) {

	int* divisori = malloc(n * sizeof(int));  // dimensione massima possibile
	if (!divisori) return NULL;

	*n_div = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			divisori[(*n_div)++] = i;
		}
	}

	return divisori;
}


bool BackTrackSomma(int* divisori, int n_div, int index, int somma_corrente, int target){
	if (somma_corrente== target) // caso uscita positivo
	{
		return true;
	}

	if (index == n_div || somma_corrente > target) // sono arrivato in fondo oppure ho sforato
	{
		return false;
	}

	return BackTrackSomma(divisori, n_div, index + 1, somma_corrente + divisori[index], target) || // prendo divisore
		BackTrackSomma(divisori, n_div, index + 1, somma_corrente, target); // non prendo   (con || se uno mi da true ritorna true e uno false provo altro e torno false solo se tutti e due false)
}


bool VerificaPseudoperfetto(int n) {

	if (n <= 0)
	{
		return false;
	}
	int n_div = 0;
	int* divisori = CalcolaDivisori(n, &n_div);

	//non ci sono divisori
	if (!divisori) return false;


	bool risultato = BackTrackSomma(divisori, n_div, 0, 0, n);

	free(divisori);
	return risultato;
}


//int main(void) {
//
//	int n = 12;
//	bool res = VerificaPseudoperfetto(n);
//}