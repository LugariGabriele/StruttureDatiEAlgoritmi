#include "minheap.h"
#include <stdlib.h>


/*
La funzione prende in input un min-heap ed estrae l'elemento minimo dallo heap, deallocando
opportunamente la memoria e assicurandosi che le proprietà min-heap siano rispettate altermine dell'operazione.
La funzione ritorna false se l'heap è vuoto, true altrimenti. La funzione salva in e l'elemento estratto.

*/

bool HeapMinPop(Heap* h, ElemType* e) {


	if (HeapIsEmpty(h))
	{
		return false;
	}

	*e = ElemCopy(&h->data[0]); // se proprietà rispettate elem minimo è radice

	//sostituico radice con ultimo elemento (così dopo posso fare size--)
	h->data[0] = h->data[h->size - 1];

	h->size--;

	h->data = realloc(h->data, h->size * sizeof(ElemType));


	//ripristino ordine partendo da radice
	HeapMinMoveDown(h, 0);

	return true;
}


// uso per essere comodo nel main
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return HeapCreateEmpty();
	}
	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < v_size; i++) {
		HeapMinInsertNode(h, &v[i]);
	}
	return h;
}



int main(void) {
	ElemType v[] = { 1,2,3,4,5,6,7,8,9,10 };
	size_t s = 10;
	Heap* h = HeapMinHeapify(v, s);
	HeapWriteStdout(h);
	ElemType r;
	bool res = HeapMinPop(h, &r);
	HeapWriteStdout(h);
	return 0;
}