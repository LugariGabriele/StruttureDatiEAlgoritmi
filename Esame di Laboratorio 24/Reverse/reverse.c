#include "reverse.h"
#include <stdlib.h>




Item* Reverse(Item* list, int right) {


	if (right <= 1 || ListIsEmpty(list))
	{
		return list;
	}

	Item* nodoRight = list;
	int count = 0;

	while (count < right && nodoRight != NULL) { // sposto puntatore fino a nodo a cui dobbiamo invertire

		nodoRight = nodoRight->next;
		count++;
	}

	Item* curr = list;
	Item* prev = NULL;
	Item* next;

	while (curr != nodoRight) {

		next = curr->next;
		curr->next = prev;


		prev = curr;
		curr = next;
	}

	//vecchio primo nodo 0 ora è ultimo di quelli invertiti ma punta ancora a 0
	list->next = nodoRight; // riattacco il resto della lista a quella invertita
	return prev;
}

//
//int main(void) {
//
//	int values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//	size_t n = sizeof(values) / sizeof(values[0]);
//
//	// Costruzione lista
//	Item* list = ListCreateEmpty();
//	for (size_t i = 0; i < n; ++i) {
//		list = ListInsertBack(list, &values[i]);
//	}
//
//	size_t right = 12; // cambia questo valore per test diversi
//
//	printf("Input:\n");
//	ListWriteStdout(list);
//
//	list = Reverse(list, right);
//
//	printf("Output:\n");
//	ListWriteStdout(list);
//
//	ListDelete(list);
//	return 0;
//}
