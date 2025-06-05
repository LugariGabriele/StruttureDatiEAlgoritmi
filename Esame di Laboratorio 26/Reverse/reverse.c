#include "reverse.h"
#include <stdlib.h>
#include <stdbool.h>

int ContaNodi(Item* l) {

	int num = 0;
	Item* tmp = l;
	while (!ListIsEmpty(tmp)) {
		num++;
		tmp = ListGetTail(tmp);
	}
	return num;
}



Item* Reverse(Item* list, int left) {

	int len = ContaNodi(list);

	if (left >= len - 1) //non devo modificare
	{
		return list;
	}

	Item* curr = list; //primo nodo da invertire
	Item* parent_non_inv = NULL; // ultimo nodo primadi quelli da invertire
	int indice = 0;
	
	while (indice != left) {
		parent_non_inv = curr;
		curr = ListGetTail(curr);
		indice++;
	}

	
	Item* prev = NULL; // ultimo nodo da scambiare
	Item* next = NULL;
	Item* start_inv = curr; // primo nodo della sottolista da invertire

	while (!ListIsEmpty(curr)) {
		next = ListGetTail(curr); // salva prossimo nodo
		curr->next = prev; // inverti collegamento
		prev = curr; //avanza prev
		curr = next; // avanza curr
	}

	if (parent_non_inv != NULL) {
		parent_non_inv->next = prev;
		return list;
	}
	else {
		return prev; // Tutta la lista è stata invertita
	}
}

//
//int main(void) {
//
//
//	int v[] = { 0,1,2,3,4,5,6,7,8 };
//	int size = sizeof(v) / sizeof(v[0]);
//
//	Item* list = ListCreateEmpty();
//	for (size_t i = 0; i < size; i++)
//	{
//		list = ListInsertBack(list, &v[i]);
//	}
//
//
//	printf("Originale: ");
//	ListWriteStdout(list);
//
//	int left = 3;
//	list = Reverse(list, left);
//
//	printf("Modificata: ");
//	ListWriteStdout(list);
//
//	ListDelete(list); // libera memoria
//}