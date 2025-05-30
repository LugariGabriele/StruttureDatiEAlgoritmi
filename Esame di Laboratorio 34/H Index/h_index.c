#include <stdlib.h>

int HIndex(const int* cits, size_t v_size) {

	if (v_size == 0 || cits == NULL)
	{
		return 0;
	}

	//array quanti articoli hanno esatamente i citazioni
	int* count = calloc(v_size + 1, sizeof(int));
	
	//riempio conteggio
	for (size_t i = 0; i < v_size; i++)
	{
		if (cits[i] >= (int)v_size) { //nessun h index può superare v_size e quindi tutti valori superiori li raggruppo in fondo
			count[v_size]++;
		}

		else if (cits[i] >= 0) {
			count[cits[i]]++;
		}
	}
	
	// Calcoliamo l'h-index a partire dai valori più alti
	int total = 0;
	for (int i = (int)v_size; i >= 0; --i) {
		total += count[i];
		if (total >= i) {
			free(count);
			return i;
		}
	}
	return 0;
}