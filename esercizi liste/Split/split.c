#include "list.h"
#include <stdbool.h>

Item* Split(Item* i) {

	if (ListIsEmpty(i))
	{
		return NULL;
	}

	int size = 0;
	Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		size++;
		tmp = ListGetTail(tmp);
	}

	//trovo punto dove tagliare
	bool pari = size % 2 == 0 ? true : false;
	int mid = size / 2;
	if (!pari)
	{
		mid++;
	}
	
	// Mi porto sul nodo prima del punto di split
	Item* curr = i;
	for (int j = 1; j < mid; j++) {
		curr = ListGetTail(curr);
	}

	Item* second_half = ListGetTail(curr);

	curr->next = NULL;


	return second_half;

}

int main(void) {

	ElemType* a = 5;
	ElemType* b = 1;
	ElemType* c = 7;
	ElemType* d = 3;

	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	ListWriteStdout(list);

	Item* list2 = Split(list);
	ListWriteStdout(list2);

}

