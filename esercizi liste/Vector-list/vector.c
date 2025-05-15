#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Item* vector2List(const ElemType* v, size_t v_size, enum ConversionType c) {

	Item* list = ListCreateEmpty();

	if (c == kInOrder)
	{
		for (int i = 0; i < v_size; i++) {
			list = ListInsertBack(list, &v[i]);
		}
	}

	else
	{
		for (int i = 0; i < v_size; i++)
		{
			list = ListInsertHead(&v[i], list);
		}
	}

	return list;
}

ElemType* List2Vector(const Item* i, size_t v_size, enum ConversionType c) {
	if (i == NULL) {
		v_size = 0;
		return NULL;
	}

	ElemType* vector = malloc(v_size * sizeof(ElemType));

	Item* curr = i;
	size_t idx = 0;

	// caso kOrder

	if (c == kInOrder)
	{
		while (!ListIsEmpty(curr)) {
			ElemType *e_curr = ListGetHeadValue(curr);
			vector[idx] = *e_curr;
			idx++;
			curr = ListGetTail(curr);
		}
	}

	else
	{
		idx = v_size - 1;
		while (!ListIsEmpty(curr)) {
			ElemType *e_curr = ListGetHeadValue(curr);
			vector[idx] = *e_curr;
			idx--;
			curr = ListGetTail(curr);
		}
	}
	return vector;
}

int main(void) {

	ElemType arr[] = { 1,2,3,4,5,6 };
	size_t n = sizeof(arr) / sizeof(arr[0]);

	printf("Conversione vettore -> lista (ordine normale):\n");
	Item* list = vector2List(arr, n, kInOrder);
	ListWriteStdout(list);

	// Conversione da lista a vettore (ordine normale)
	ElemType* vec = List2Vector(list, n, kInOrder);
	printf("\n\nConversione lista -> vettore (ordine normale):\n");
	for (size_t i = 0; i < n; ++i) {
		ElemWriteStdout(&vec[i]);
		printf("\n");
	}

	// Pulizia
	free(vec);
}