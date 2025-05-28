#include "maxheap.h"

/*
deve salvare elemento massimo
*/

bool HeapMaxPop(Heap* h, ElemType* e) {


	if (HeapIsEmpty(h))
	{
		return false;
	}

	*e = h->data[0];

	h->data[0] = h->data[h->size - 1];
	h->size--;
	HeapMaxMoveDown(h, 0);

	return true;
}