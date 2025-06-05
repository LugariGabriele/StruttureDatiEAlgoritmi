#include "sum_dlist.h"
#include <stdio.h>
#include <stdlib.h>



Item* DListSum(const Item* i1, const Item* i2) {

	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}

	// Caso una sola lista vuota: restituisci copia dell'altra
	if (DListIsEmpty(i1)) {
		Item* res = DListCreateEmpty();
		for (const Item* tmp = i2; tmp != NULL; tmp = tmp->next) {
			res = DListInsertBack(res, &tmp->value);
		}
		return res;
	}

	if (DListIsEmpty(i2)) {
		Item* res = DListCreateEmpty();
		for (const Item* tmp = i1; tmp != NULL; tmp = tmp->next) {
			res = DListInsertBack(res, &tmp->value);
		}
		return res;
	}


	const Item* t1 = i1;
	while (t1->next != NULL) { // sposto alla cifra meno significativa
		t1 = t1->next;
	}

	const Item* t2 = i2;
	while (t2->next != NULL) { // sposto alla cifra meno significativa
		t2 = t2->next;
	}

	int riporto = 0;
	Item* result = DListCreateEmpty();

	while (t1 != NULL || t2 != NULL || riporto > 0) {

		int v1 = t1 ? *DListGetHeadValue(t1) : 0; // se non è null prendo numero
		int v2 = t2 ? *DListGetHeadValue(t2) : 0;

		int sum = v1 + v2 + riporto;

		ElemType digit = sum % 10; // prendo cifra minore di 10
		riporto = sum / 10; // se ho somma maggiore di 10 riporto va a 1

		result = DListInsertHead(&digit, result);
		//scorro indietro liste
		if (t1 != NULL)
		{
			t1 = DListGetPrev(t1);
		}
		if (t2 != NULL)
		{
			t2 = DListGetPrev(t2);
		}
	}

	return result;
}

//
//int main(void) {
//	Item* l1 = DListCreateEmpty();
//	int a[] = { 9, 5, 4 };  // 954
//	for (int i = 0; i < 3; i++) {
//		l1 = DListInsertBack(l1, &a[i]);
//	}
//
//	Item* l2 = DListCreateEmpty();
//	int b[] = { 6, 9 };     // 69
//	for (int i = 0; i < 2; i++) {
//		l2 = DListInsertBack(l2, &b[i]);
//	}
//
//	Item* sum = DListSum(l1, l2); // Expected: 1 0 2 3
//	DListWriteStdout(sum); // Stampa il risultato
//
//	DListDelete(l1);
//	DListDelete(l2);
//	DListDelete(sum);
//	return 0;
//}