#include "maxheap.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Pop(Heap* h, ElemType* popped) {
	if (h->size == 0) {
		popped = NULL;
		return;
	}
	*popped = ElemCopy(&h->data[0]);
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	HeapMaxMoveDown(h, 0);
	return;
}


int MangiaCaramelle(Heap* h, int k) {

	if (h == NULL || h->size == 0)
		return 0;

	int totale = 0;
	for (size_t i = 0; i < h->size; i++)
	{
		totale += h->data[i];
	}

	if (k == 0)
	{
		return totale;
	}

	for (size_t secondi = 0; secondi < k; secondi++)
	{
		if (h->size == 0) break;

		ElemType sacchetto; // essendo max int sacchetto da usare sarà sempre la radice dato che più grande
		Pop(h, &sacchetto);

		
		int mangiate = sacchetto - floor(sqrt(sacchetto));
		int rimaste_sacchetto = sacchetto - mangiate;
		totale -= mangiate;

		// se rimangono caramelle reinserisco pacchetto così riordino
		if (rimaste_sacchetto > 0)
		{
			HeapMaxInsertNode(h, &rimaste_sacchetto);
		}
	}
	return totale;
}

//int main(void) {
//	// Creo un heap vuoto
//	Heap* h = HeapCreateEmpty();
//
//	// Dati esempio: {100, 25, 64, 9, 4}
//	int dati[] = { 100, 25, 64, 9, 4 };
//	int n = sizeof(dati) / sizeof(dati[0]);
//
//	// Inserisco i dati nell'heap
//	for (int i = 0; i < n; i++) {
//		ElemType val = dati[i];
//		HeapMaxInsertNode(h, &val);
//	}
//
//	// Stampo heap iniziale
//	printf("Heap iniziale:\n");
//	HeapWriteStdout(h);
//
//	int k = 4; // secondi
//
//	// Chiamo la funzione MangiaCaramelle
//	int risultato = MangiaCaramelle(h, k);
//
//	// Stampo risultato
//	printf("Caramelle rimaste dopo %d secondi: %d\n", k, risultato);
//
//
//
//	return 0;
//}