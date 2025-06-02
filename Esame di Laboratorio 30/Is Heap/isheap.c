#include "minheap.h"
#include <stdbool.h>

bool IsHeap(const Heap* h) {

	if (HeapIsEmpty(h))
	{
		return false;
	}
	if (h == NULL) {
		return false;
	}


	// min heap figli maggiori di padre
	for (int i = 0; i < (int)h->size; i++)
	{
		int l = HeapLeft(i);
		int r = HeapRight(i);

		if (l < (int)h->size)
		{
			if (ElemCompare(&h->data[i], &h->data[l]) > 0) { // padre maggiore figlio
				return false;
			}
		}

		if (r < (int)h->size)
		{
			if (ElemCompare(&h->data[i], &h->data[r]) > 0) { // padre maggiore figlio
				return false;
			}
		}
	}

	return true;
}
