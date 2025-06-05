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
	if (ListIsEmpty(list))
	{
		return list;
	}

	int len = ContaNodi(list);
	if (n == 0) return list;

	n = n % (len-1);
	int idx = 0;
	
	while (n > 0) {
		
		int i = idx;
		int j = idx - 1;
		Item* curr = list;
		//aggiorno curr per puntare il primo elem
		while (i > 0 ) {
			curr = ListGetTail(curr);
			i--;
		}

		Item* first = curr;
		Item* second = ListGetTail(first);
		Item* second_next = ListGetTail(second);
		Item* prev = list;

		//sposto prev a elem prima di curr(quindi di quello da spostare)
		while (j > 0) {
			prev = ListGetTail(prev);
			j--;
		}



		if (idx == 0)
		{
			list = second; // metto puntatore su list e quindi taglio il primo elem
			second->next = first;
			first->next = second_next;
		}
		else
		{
			prev->next = second;
			second->next = first;
			first->next = second_next;

		}

		idx++;
		n--;
	}

	return list;
}


int main(void) {
	// Crea lista: [0, 1, 2, 3]
	Item* list = ListCreateEmpty();
	for (int i = 3; i >= 0; --i) {
		list = ListInsertHead(&i, list);
	}

	printf("Lista originale: ");
	ListWriteStdout(list);

	size_t n = 5;
	list = ShiftN(list, n);

	printf("Lista dopo ShiftN di %zu: ", n);
	ListWriteStdout(list);

	ListDelete(list);
	return 0;
}
