#include "gemelli.h"
#include <stdlib.h>
#include <stdio.h>

int SommaGemelli(const Item* i) {
	if (ListIsEmpty(i) || ListGetTail(i) == NULL) {
		return 0;
	}

	int somma_max = 0;

	//conto numero elementi
	const Item* tmp = i;
	size_t n = 0;
	while (!ListIsEmpty(tmp)) {
		n++;
		tmp = ListGetTail(tmp);
	}

	for (size_t left = 0; left < n / 2; left++) {
		// Prendo il valore in posizione left
		const Item* p_left = i;
		for (size_t k = 0; k < left; k++) {
			p_left = ListGetTail(p_left);
		}

		// Prendo il valore in posizione right = n - 1 - left
		const Item* p_right = i;
		size_t right = n - 1 - left;
		for (size_t k = 0; k < right; k++) { // arrivo al valore
			p_right = ListGetTail(p_right);
		}

		int  somma = *ListGetHeadValue(p_left) + *ListGetHeadValue(p_right);
		if (somma > somma_max) {
			somma_max = somma;
		}
	}


	return somma_max;
}
//
//int main(void) {
//
//	Item* lista = ListCreateEmpty();
//	ElemType* a = 5;
//	ElemType* b = 0;
//	ElemType* c = 12;
//	ElemType* d = 8;
//	ElemType* e = 1;
//	lista = ListInsertBack(lista, &a);
//	lista = ListInsertBack(lista, &b);
//	lista = ListInsertBack(lista, &c);
//	lista = ListInsertBack(lista, &d);
//	lista = ListInsertBack(lista, &e);
//
//
//	int max_somma = SommaGemelli(lista);
//	printf("Somma massima gemelli: %d\n", max_somma);
//
//}