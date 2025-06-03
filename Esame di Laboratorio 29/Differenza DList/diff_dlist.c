#include "diff_dlist.h"
#include <stdio.h>
#include <stdlib.h>


const Item* GetLast(const Item* i) {
	while (i && i->next != NULL) {
		i = i->next;
	}
	return i;
}

Item* DListDiff(const Item* i1, const Item* i2) {

	if (DListIsEmpty(i1) && DListIsEmpty(i2))
	{
		return DListCreateEmpty();
	}

	if (DListIsEmpty(i2))
	{
		Item* res = i1;
		return res;
	}

	const Item* n1 = GetLast(i1);
	const Item* n2 = GetLast(i2);
	Item* diff = DListCreateEmpty();

	int resto = 0;

	while (n1 != NULL || n2 != NULL) {
		int num1 = n1 ? *DListGetHeadValue(n1) : 0; //puntatore in fondo quindi testa corrisponde a dove è puntatore
		int num2 = n2 ? *DListGetHeadValue(n2) : 0;

		num1 -= resto; // se ho sottrazione - precedente ho tolto uno e prestato a quella prima 

		int sub = num1 - num2;

		if (sub < 0)
		{
			sub += 10;
			resto = 1;
		}
		else
		{
			resto = 0;
		}

		diff = DListInsertHead(&sub, diff);
		if (!DListIsEmpty(n1))
		{
			n1 = n1->prev;
		}

		if (!DListIsEmpty(n2))
		{
			n2 = n2->prev;
		}
	}

	// Rimuovi eventuali zeri iniziali
	while (!DListIsEmpty(diff) && *DListGetHeadValue(diff) == 0 && diff->next) {
		Item* temp = diff;
		diff = diff->next;
		diff->prev = NULL;
		free(temp);
	}


	return diff;
}


//
//// Funzione di utilità per creare una lista da un array
//Item* DListFromArray(const int* arr, size_t size) {
//	Item* list = DListCreateEmpty();
//	for (size_t i = 0; i < size; ++i) {
//		list = DListInsertBack(list, &arr[i]);
//	}
//	return list;
//}
//
//int main() {
//	int a[] = { 9, 5, 4 };     // rappresenta 954
//	int b[] = { 6, 9 };        // rappresenta 69
//
//	Item* i1 = DListFromArray(a, sizeof(a) / sizeof(int));
//	Item* i2 = DListFromArray(b, sizeof(b) / sizeof(int));
//
//	printf("Numero 1: ");
//	DListWriteStdout(i1);
//	printf("\n");
//
//	printf("Numero 2: ");
//	DListWriteStdout(i2);
//	printf("\n");
//
//	Item* result = DListDiff(i1, i2);
//
//	printf("Differenza: ");
//	DListWriteStdout(result);
//	printf("\n");
//
//	// Pulizia memoria
//	DListDelete(i1);
//	DListDelete(i2);
//	DListDelete(result);
//
//	return 0;
//}