#include "minheap.h"
#include <stdlib.h>

void Pop(Heap* h, ElemType* popped) { //O(logn)
	if (h->size == 0) {
		popped = NULL;
		return;
	}

	*popped = ElemCopy(&h->data[0]);
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	HeapMinMoveDown(h, 0);
	return;
}
int SumSmallest(Heap* h, size_t k1, size_t k2) {

	if (k2 <= k1 + 1 || h->size <= k1 || HeapIsEmpty(h))
	{
		return 0;
	}

	Heap* copy = malloc(sizeof(Heap));
	copy->size = h->size;
	copy->data = malloc(sizeof(ElemType) * copy->size);
	for (size_t i = 0; i < copy->size; ++i) {
		copy->data[i] = ElemCopy(&h->data[i]);
	}

	int sum = 0;
	ElemType popped;

	for (size_t i = 0; i < k2 && copy->size > 0; ++i) { //O(k2)
		Pop(copy, &popped); // ritorna puntatore a valore min espulso(primo elem)

		size_t pos = i + 1; // indice heap parte da 1
		if (pos > k1 && pos < k2) {
			sum += popped;
		}
	}

	// Pulisce la memoria
	for (size_t i = 0; i < copy->size; ++i) {
		ElemDelete(&copy->data[i]);
	}
	free(copy->data);
	free(copy);

	return sum;

}