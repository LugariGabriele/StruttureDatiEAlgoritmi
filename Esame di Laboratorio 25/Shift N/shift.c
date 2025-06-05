#include "shift.h"
#include<stdlib.h>
#include<stdio.h>

int ContaNodi(Item* l) {

	Item* curr = l;
	int count = 0;
	while (!ListIsEmpty(curr)) {
		curr = ListGetTail(curr);
		count++;
	}

	return count;
}

Item* ShiftN(Item* list, size_t n) {

	int len = ContaNodi(list);
	if (n == 0) return list;

	n = n % len;

	while (n > 0) {

		Item* first = list;
		Item* second = ListGetTail(first);



		//trova ultimo nodo
		Item* last = first;
		while (!ListIsEmpty(last->next)) {
			last = last->next;
		}

		//sposta first dopo last
		list = second;
		first->next = NULL;
		last->next = first;

		n--;
	}

	return list;
}
//
//int main(void) {
//	// Crea lista: [0, 1, 2, 3]
//	Item* list = ListCreateEmpty();
//	for (int i = 3; i >= 0; --i) {
//		list = ListInsertHead(&i, list);
//	}
//
//	printf("Lista originale: ");
//	ListWriteStdout(list);
//
//	size_t n = 2;
//	list = ShiftN(list, n);
//
//	printf("Lista dopo ShiftN di %zu: ", n);
//	ListWriteStdout(list);
//
//	ListDelete(list);
//	return 0;
//}
