#include "list.h"


//lista data è ordinata in modo cresciente o vuota

Item* InsertOrdIter(const ElemType* e, Item* i) {

	Item* new_node = ListCreateEmpty();
	new_node = ListInsertHead(e, new_node); // creo nodo con valore e

	if (ListIsEmpty(i) || ElemCompare(e, ListGetHeadValue(i)) <= 0) { //e <= elem testa i 
		// Inserisco in testa
		new_node->next = i;
		return new_node;
	}

	// Scorri la lista finché il prossimo valore è minore di e
	Item* prev = i;
	while (prev->next != NULL && ElemCompare(e, ListGetHeadValue(prev->next)) > 0) {
		prev = prev->next;
	}

	// Inserisci tra prev e prev->next
	new_node->next = prev->next;
	prev->next = new_node;

	return i;

}




Item* InsertOrd(const ElemType* e, Item* i) { // versione Ricorsiva

	if (ListIsEmpty(i) || ElemCompare(e, ListGetHeadValue(i)) <= 0) {
		// Inserisci in testa
		return ListInsertHead(e, i);
	}

	// Ricorsione sulla coda
	i->next = InsertOrd(e, i->next);
	return i;
}


int main(void) {
	int a = 1, b = 3, c = 5, d = 7;
	int to_insert = 4;

	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &a);
	list = ListInsertBack(list, &b);
	list = ListInsertBack(list, &c);
	list = ListInsertBack(list, &d);

	printf("Lista originale:\n");
	ListWriteStdout(list);

	// Test iterativo
	list = InsertOrdIter(&to_insert, list);
	printf("\nDopo InsertOrdIter(4):\n");
	ListWriteStdout(list);

	// Test ricorsivo
	ElemType to_insert2 =2;
	Item *list2 = InsertOrd(&to_insert2, list);
	printf("\nDopo InsertOrd(2):\n");
	ListWriteStdout(list2);
}