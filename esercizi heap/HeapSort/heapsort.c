#include "minheap.h"

/*

La funzione prende in input un min-heap e lo trasforma in modo tale che al termine dell'esecuzione l'array dei dati sia ordinato in senso decrescente. 
La funzione deve sfruttare le propriet� dell'heap e non deve fare uso di altri algoritmi di ordinamento.

*/


void HeapMinHeapsort(Heap* h) {

	if (HeapIsEmpty(h)) {
		return;
	}

	size_t original_size = h->size; // salvo dimensione originaria per ripristinarla al termine 

	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1)); // scambio elemento pi� piccolo con ultimo cos� faccio movedown (simile a pop)
		h->size--; //ho elem pi� piccolo in fondo array quindi lo lascio l� e riduco size
		HeapMinMoveDown(h, 0); // metto elemento pi� piccolo tra rimanenti come radice (e poi lo riscambio con elemento pi� in fondo...)
	}

	h->size = original_size;

	return h;
}

